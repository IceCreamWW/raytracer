//
// Created by icecreamww on 2020/6/13.
//

#ifndef MRAYTRACER_TRIANGLE_HPP
#define MRAYTRACER_TRIANGLE_HPP

#include "Object.hpp"
class Triangle : public Object {
public:
  Triangle(const Point3f &A, const Point3f &B, const Point3f &C,
           const Point3f &face, const Material &material);
  bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;
  Vector3f normal(const Point3f &point) override;

private:
  float area(const Point3f &x, const Point3f &y, const Point3f &z);
  Point3f A, B, C;
  float D;
  Vector3f normal_;
  float area_;
};

#endif // MRAYTRACER_TRIANGLE_HPP
