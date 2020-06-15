//
// Created by icecreamww on 2020/6/13.
//

#ifndef MRAYTRACER_SQUARE_HPP
#define MRAYTRACER_SQUARE_HPP

#include "Object.hpp"

class Square : public Object {
public:
  Square(const Material &material, const Point3f &a, const Point3f &b,
         const Point3f &c, const Point3f &d, const Point3f &face);
  bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                     float &t0) override;

  Vector3f normal(const Point3f &point) override;

private:

  Point3f a, b, c, d;
  Point3f face;
  Vector3f normal_;

};

#endif // MRAYTRACER_SQUARE_HPP
