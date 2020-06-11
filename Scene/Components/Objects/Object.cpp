//
// Created by icecreamww on 2020/6/10.
//

#include "Object.hpp"

Object::Object(Material material): material(material) {}

bool Object::ray_intersect(const Point3f &orig, const Vector3f &dir, float &t0) {
  return false;
}

Vector3f Object::normal(const Point3f &point, const Vector3f &dir) { return Vector3f(); }
