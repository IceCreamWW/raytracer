//
// Created by icecreamww on 2020/6/10.
//

#include "Sphere.hpp"
Sphere::Sphere(Point3f center, float radius, Color color,
               float alpha)
    : Shape(color, alpha), center(center), radius(radius) {}

 bool Sphere::ray_intersect(const glm::vec3 &orig, const glm::vec3 &dir,
                           float &t0) {
  Vector3f vco = center - orig;            // o to c vector
  float op = glm::dot(vco, dir);            // project of oc on dir
  float cp2 = glm::dot(vco, vco) - op * op; // distance^2 from c to p
  if (cp2 > radius * radius)                // distance > radius
    return false;

  float pt0 = sqrtf(radius * radius - cp2);
  t0 = op - pt0;
  float t1 = op + pt0;

  // when origin of the ray is inside the sphere
  if (t0 < 0) t0 = t1;
  return true;
}
