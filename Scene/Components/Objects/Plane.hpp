//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_PLANE_HPP
#define MRAYTRACER_PLANE_HPP

#include "Object.hpp"

class Plane : public Object {
public:
  Plane(const Point3f &p, const Vector3f &normal, const Material &material);
  bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;
  Vector3f normal(const Point3f &point) override;

private:
  Point3f p;
  Vector3f normal_;
  float D;

};

#endif // MRAYTRACER_PLANE_HPP
