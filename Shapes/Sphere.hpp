//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_SPHERE_HPP
#define MRAYTRACER_SPHERE_HPP

#include "Shape.hpp"
class Sphere : public Shape {
public:
  Sphere(Point3f center, float radius, Vector3f color, float alpha=1);

  virtual bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;

  Point3f center;
  float radius;
};

#endif // MRAYTRACER_SPHERE_HPP
