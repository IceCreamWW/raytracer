//
// Created by icecreamww on 2020/6/10.
//

#include "Scene.hpp"
Scene::Scene(int width, int height, float fov)
    : image(new Image(width, height)), fov(fov), background(Color(1)) {}

Scene::Scene(int width, int height, float fov, Color background)
    : image(new Image(width, height)), fov(fov), background(background) {}

Color Scene::cast_ray(const Point3f &orig, const Vector3f &dir) {

  float min_distance = std::numeric_limits<float>::max();

  Color color = background;
  for (auto shape : shapes) {
    float distance;
    bool has_intersection = shape->ray_intersect(orig, dir, distance);
    if (has_intersection && distance < min_distance) {
      color = shape->color;
      min_distance = distance;
    }
  }
  return color;
}

void Scene::render() {
  /**
   * Denote distance from origin to screen is z pixels
   * We have:
   *    z * tan(fov / 2) = width / 2
   *    z = width / (w * tan(fov / 2))
   */

  float x = -image->width / 2 - 0.5f;
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
      image->pixels[i][j] = cast_ray(orig, dir);
    }
  }
}

void Scene::write_to_file(string filename) {
  image->write_to_file(filename);
}

void Scene::push(Shape *shape) { shapes.push_back(shape); }

Scene::~Scene() {
  delete image;
  for (auto shape : shapes)
    delete shape;
}
