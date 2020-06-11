//
// Created by icecreamww on 2020/6/10.
//

#include "Scene.hpp"
#define MAX_DEPTH 4

Scene::Scene(int width, int height, float fov)
    : image(new Image(width, height)), fov(fov), background(Color(0)) {}

Scene::Scene(int width, int height, float fov, Color background)
    : image(new Image(width, height)), fov(fov), background(background) {}

Color Scene::cast_ray(const Point3f &orig, const Vector3f &dir, int depth) {

  Vector3f N, hit;
  Material material;
  if (depth > MAX_DEPTH || !trace(orig, dir, N, hit, material)) {
    return background;
  }

  float diffuse_intensity = 0;
  float specular_intensity = 0;

  Color reflect_color(0);
  if (material.albedo != 0) {
    Vector3f reflect_dir = glm::reflect(dir, N);
    Point3f reflect_orig = move_epsilon(hit, reflect_dir, N);
    reflect_color = cast_ray(reflect_orig, reflect_dir, depth + 1);
  }

  Color refract_color(0);
  if (material.opacity != 0) {
    Vector3f refract_dir;
    if (glm::dot(dir, N) < 0) // from outside to inside
      refract_dir = glm::refract(dir, N, 1/material.eta);
     else                     // from inside to outside
      refract_dir = glm::refract(dir, -N, material.eta);
    Point3f refract_orig = move_epsilon(hit, refract_dir, N);
    refract_color = cast_ray(refract_orig, refract_dir, depth + 1);
  }

  for (auto light : lights) {
    Vector3f light_dir = glm::normalize(hit - light->position);

    if (is_shadow(light, hit, N))
      continue;

    diffuse_intensity +=
        light->intensity_at(hit) * std::max(0.f, glm::dot(-light_dir, N));

    specular_intensity +=
        light->intensity_at(hit) *
        std::max(0.f,
                 powf(std::max(0.f, glm::dot(glm::reflect(-light_dir, N), dir)),
                      material.n));
  }

  return material.color * (material.kd * diffuse_intensity) +
         WHITE * (material.ks * specular_intensity) +
         reflect_color * material.albedo +
         refract_color * material.opacity;
}

void Scene::render() {
  /**
   * Denote distance from origin to screen is z pixels
   * We have:
   *    z * tan(fov / 2) = width / 2
   *    z = width / (w * tan(fov / 2))
   */

  float x;
  float y = image->height / 2 + 0.5f;
  float z = -image->width / (2 * tan(fov / 2.f));
  Point3f orig(0);

  for (size_t i = 0; i < image->height; ++i) {
    x = -image->width / 2 - 0.5f;
    --y;
    for (size_t j = 0; j < image->width; ++j) {
      ++x;
      if (x == 0.5 && y == 0.5)
        x = x;
      Vector3f dir = glm::normalize(Vector3f(x, y, z));
      image->pixels[i][j] = cast_ray(orig, dir, 0);
    }
  }
}

void Scene::write_to_file(string filename) { image->write_to_file(filename); }

void Scene::push(Object *object) { objects.push_back(object); }

void Scene::push(Light *light) { lights.push_back(light); }

Scene::~Scene() {
  delete image;
  for (auto object : objects)
    delete object;
  for (auto light : lights)
    delete light;
}

bool Scene::trace(const Point3f &orig, const Vector3f &dir, Vector3f &N,
                  Vector3f &hit, Material &material) {
  float min_distance = std::numeric_limits<float>::max();
  bool has_intersection = false;
  for (auto object : objects) {
    float distance;
    if (object->ray_intersect(orig, dir, distance) && distance < min_distance) {
      has_intersection = true;
      min_distance = distance;
      hit = orig + dir * distance;
      N = object->normal(hit, dir);
      material = object->material;
    }
  }
  return has_intersection;
}

Point3f Scene::move_epsilon(const Point3f &orig, const Vector3f &dir,
                                    const Vector3f &N) {
  return glm::dot(dir, N) < 0 ? orig - N * 1e-3f : orig + N * 1e-3f;
}


bool Scene::is_shadow(Light *light, const Point3f &hit, const Vector3f &N) {
  Vector3f light_dir = glm::normalize(light->position - hit);
  Point3f shadow_orig = move_epsilon(hit, light_dir, N);
  Point3f shadow_hit, v;
  Material m;
  return (trace(shadow_orig, light_dir, v, shadow_hit, m) &&
          glm::length(shadow_hit - shadow_orig) <
          glm::length(hit - light->position));
}
