//
// Created by icecreamww on 2020/6/14.
//

#ifndef MRAYTRACER_CONE_HPP
#define MRAYTRACER_CONE_HPP

#include "Object.hpp"
class Cone : public Object {
public:
  Cone(const Point3f &center, float radius,
       float height, const Material &material);
  bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;
  Vector3f normal(const Point3f &point) override;

private:
  Point3f center;
  float radius;
  float height;
  float tan;
  float tan2;
};

#endif // MRAYTRACER_CONE_HPP
