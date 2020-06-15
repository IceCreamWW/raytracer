//
// Created by icecreamww on 2020/6/13.
//

#include "Circle.hpp"

Circle::Circle(const Point3f &center, float radius,
               const Vector3f &normal, const Material &material)
    : Object(material), center(center), radius(radius), normal_(normal) {
  D = glm::dot(normal_, center);
}

bool Circle::ray_intersect(const Point3f &orig, const Vector3f &dir,
                           float &t0) {

  t0 = (D - glm::dot(normal_, orig)) / glm::dot(normal_, dir);

  if (t0 < 0)
    return false;

  Point3f hit = orig + t0 * dir;

  return (glm::length(hit - center) <= radius);
}

Vector3f Circle::normal(const Point3f &point) { return normal_; }

