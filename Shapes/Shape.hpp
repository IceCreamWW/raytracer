//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_SHAPE_HPP
#define MRAYTRACER_SHAPE_HPP

#include "glm/gtc/matrix_transform.hpp"
typedef glm::vec3 Color;
typedef glm::vec3 Vector3f;
typedef glm::vec3 Point3f;

class Shape {
public:
  glm::vec3 color;
  float alpha;


  Shape(const Color &color, float alpha=1);

  /**
   * calculate the intersection between a ray and a object
   * @param orig origin of the ray
   * @param dir direction of the ray
   * @param t0 distance of origin to first intersection
   * @return if the ray intersects with the shape
   */
  virtual bool ray_intersect(const Point3f &orig, const Vector3f &dir,
                             float &t0);
};

#endif // MRAYTRACER_SHAPE_HPP
