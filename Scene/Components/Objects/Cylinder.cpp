//
// Created by icecreamww on 2020/6/11.
//

#include "Cylinder.hpp"
Cylinder::Cylinder(const Point3f &center, float radius, float height,
                   const Material &material)
    : Object(material), center(center), radius(radius), height(height) {}

bool Cylinder::ray_intersect(const Point3f &orig, const Vector3f &dir,
                             float &t0) {
  Vector2f vco = Vector2f(center.x - orig.x, center.z - orig.z);            // o to c vector
  Vector2f dir2d = glm::normalize(Vector2f(dir.x, dir.z));
  float op = glm::dot(vco, dir2d);            // project of oc on dir

  float cp2 = glm::dot(vco, vco) - op * op; // distance^2 from c to p
  if (cp2 > radius * radius)                // distance > radius
    return false;

  float pt0 = sqrtf(radius * radius - cp2);
  t0 = op - pt0;
  float t1 = op + pt0;

  // when origin of the ray is inside the sphere
  if (t0 < 0) t0 = t1;
  if (t0 < 0) return false;

  float h = t0 / glm::length(Vector2f(dir.x, dir.z)) * dir.y + orig.y;
  return !(h > center.y + height || h < center.y);
}

Vector3f Cylinder::normal(const Point3f &point) {
  return glm::normalize(Vector3f(point.x - center.x, 0.f, point.z - center.z));
}
