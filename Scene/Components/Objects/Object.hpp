//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_OBJECT_HPP
#define MRAYTRACER_OBJECT_HPP

#include "Definitions.hpp"
#include "Material.hpp"

class Object {
public:
  Material material;

  Object(Material material);

  /**
   * calculate the intersection between a ray and a object
   * @param orig origin of the ray
   * @param dir direction of the ray
   * @param t0 distance of origin to first intersection
   * @return if the ray intersects with the shape
   */
  virtual bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                             float &t0);



  // assume point is on surface of the shape
  virtual Vector3f normal(const Point3f &point, const Vector3f &dir);
};

#endif // MRAYTRACER_OBJECT_HPP
