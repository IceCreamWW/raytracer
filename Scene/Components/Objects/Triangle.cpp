//
// Created by icecreamww on 2020/6/13.
//

#include "Triangle.hpp"
bool Triangle::ray_intersect(const Point3f &orig, const Vector3f &dir,
                             float &t0) {

  t0 = (D - glm::dot(normal_, orig)) / glm::dot(normal_, dir);

  if (t0 < 0)
    return false;

  Point3f hit = orig + t0 * dir;
  float area1 = area(hit, A, B);
  float area2 = area(hit, B, C);
  float area3 = area(hit, A, C);

  if (abs(area1 + area2 + area3 - area_) < 1e-3)
    return true;
  return false;
}

float Triangle::area(const Point3f &x, const Point3f &y, const Point3f &z) {
  float a = glm::length(y - x);
  float b = glm::length(z - y);
  float c = glm::length(x - z);
  float p = (a + b + c) / 2.f;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

Vector3f Triangle::normal(const Point3f &point) { return normal_; }

Triangle::Triangle(const Point3f &A, const Point3f &B, const Point3f &C,
                   const Point3f &face, const Material &material)
    : Object(material), A(A), B(B), C(C) {
  Vector3f v1 = B - A;
  Vector3f v2 = C - B;

  normal_ = glm::cross(v1, v2);

  if (glm::dot(normal_, face - A) < 0)
    normal_ = -normal_;
  normal_ = glm::normalize(normal_);

  area_ = area(A,B,C);

  D = glm::dot(normal_, A);
}
