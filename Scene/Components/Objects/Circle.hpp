//
// Created by icecreamww on 2020/6/14.
//

#ifndef MRAYTRACER_CIRCLE_HPP
#define MRAYTRACER_CIRCLE_HPP

#include "Object.hpp"
class Circle: public Object {
public:
  bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;
  Vector3f normal(const Point3f &point) override;
private:
public:
  Circle(const Point3f &center, float radius,
         const Vector3f &normal, const Material &material);
private:
  Point3f center;
  float radius;
  Vector3f normal_;
  float D;
};

#endif // MRAYTRACER_CIRCLE_HPP
