//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_SPHERE_HPP
#define MRAYTRACER_SPHERE_HPP

#include "Object.hpp"
class Sphere : public Object {
public:
  Sphere(Point3f center, float radius, const Material &material);

  virtual bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;

  Vector3f normal(const Point3f &point, const Vector3f &dir) override;

  Point3f center;
  float radius;
};

#endif // MRAYTRACER_SPHERE_HPP
