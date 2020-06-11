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
  Scene(int width, int height, float fov, Color background);
  Color cast_ray(const Point3f &orig, const Vector3f &dir, int depth);
  void render();
  void push(Object *object);
  void push(Light *light);
  void write_to_file(string filename);
  bool trace(const Point3f &orig, const Vector3f &dir, Vector3f &N, Point3f &hit, Material &material);
  virtual ~Scene();

private:
  float fov;              // in radius (0 < fov < pi)
  Image *image;
  Color background;
  vector<Object*> objects;
  vector<Light*> lights;
};

#endif // MRAYTRACER_SCENE_HPP
