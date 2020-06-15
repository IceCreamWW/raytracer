//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_SCENE_HPP
#define MRAYTRACER_SCENE_HPP

#include "Image.hpp"
#include "Light.hpp"
#include "Object.hpp"
#include "Material.hpp"
#include <vector>

class Scene {
public:
  Scene(int width, int height, float fov);
  Scene(int width, int height, float fov, Color background, float Ia);
  Color cast_ray(const Point3f &orig, const Vector3f &dir, int depth);
  void render();
  void push(Object *object);
  void push(Light *light);
  void write_to_file(string filename);
  bool trace(const Point3f &orig, const Vector3f &dir, Vector3f &N, Point3f &hit, Material &material);
  void set_pixel_map(Image *pixelmap_image);
  Color background(const Vector3f &dir);
  virtual ~Scene();

private:
  float fov;              // in radius (0 < fov < pi)
  Image *image;
  Image *pixelmap;
  Color background_color;
  float Ia;
  vector<Object*> objects;
  vector<Light*> lights;
  Point3f move_epsilon(const Point3f &orig, const Vector3f &dir, const Vector3f &N);
  bool is_shadow(Light *light, const Point3f &hit, const Vector3f &N);
};

#endif // MRAYTRACER_SCENE_HPP
