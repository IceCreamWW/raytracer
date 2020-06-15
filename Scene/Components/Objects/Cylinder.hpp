//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_CYLINDER_HPP
#define MRAYTRACER_CYLINDER_HPP

#include "Object.hpp"
class Cylinder : public Object {
public:
  Cylinder(const Point3f &center, float radius,
           float height, const Material &material);
  bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;
  Vector3f normal(const Point3f &point) override;

private:
  Point3f center;
  float radius;
  float height;

};

#endif // MRAYTRACER_CYLINDER_HPP
