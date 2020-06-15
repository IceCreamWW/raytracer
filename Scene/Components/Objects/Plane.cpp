//
// Created by icecreamww on 2020/6/11.
//

#include "Plane.hpp"

Plane::Plane(const Point3f &p, const Vector3f &normal, const Material &material)
    : Object(material), p(p), normal_(normal) {
  D = glm::dot(normal_, p);
}
bool Plane::ray_intersect(const Point3f &orig, const Vector3f &dir, float &t0) {
  t0 = (D - glm::dot(normal_, orig)) / glm::dot(normal_, dir);
  return t0 >= 0;
}
Vector3f Plane::normal(const Point3f &point) { return normal_; }
