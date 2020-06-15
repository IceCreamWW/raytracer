//
// Created by icecreamww on 2020/6/13.
//

#include "Square.hpp"
bool Square::ray_intersect(const Point3f &orig, const Vector3f &dir,
                           float &t0) {
  return Object::ray_intersect(orig, dir, t0);
}

Vector3f Square::normal(const Point3f &point) {return normal_;}

Square::Square(const Material &material, const Point3f &a, const Point3f &b,
               const Point3f &c, const Point3f &d, const Point3f &face)
    : Object(material), a(a), b(b), c(c), d(d), face(face) {

  Vector3f v1 = b - a;
  Vector3f v2 = c - b;
  Vector3f v3 = face - a;

  normal_ = glm::cross(v1, v2);

  if (glm::dot(v3, normal_) < 0)
    normal_ = -normal_;
  normal_ = glm::normalize(normal_);
}
