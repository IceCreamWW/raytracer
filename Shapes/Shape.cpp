//
// Created by icecreamww on 2020/6/10.
//

#include "Shape.hpp"
Shape::Shape(const Vector3f &color, float alpha)
    : color(color), alpha(alpha) {}

bool Shape::ray_intersect(const Point3f &orig, const Vector3f &dir, float &t0) {
  return false;
}
