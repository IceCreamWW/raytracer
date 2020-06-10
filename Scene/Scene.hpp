//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_SCENE_HPP
#define MRAYTRACER_SCENE_HPP

#include "Image.hpp"
#include "Shapes/Shape.hpp"
#include <vector>


class Scene {
public:
  Scene(int width, int height, float fov);
  Scene(int width, int height, float fov, Color background);
  Color cast_ray(const Point3f &orig, const Vector3f &dir);
  void render();
  void push(Shape *shape);
  void write_to_file(string filename);
  virtual ~Scene();

private:
  float fov;              // in radius (0 < fov < pi)
  Image *image;
  Color background;
  vector<Shape*> shapes;
};

#endif // MRAYTRACER_SCENE_HPP
