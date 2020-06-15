//
// Created by icecreamww on 2020/6/14.
//

#include "Cone.hpp"
#include <algorithm>
Cone::Cone(const Point3f &center, float radius, float height,
           const Material &material)
    : Object(material), center(center), radius(radius), height(height) {
  tan = radius / height;
  tan2 = tan * tan;
}

bool Cone::ray_intersect(const Point3f &orig, const Vector3f &dir, float &t0) {
  float x0c = orig.x - center.x;
  float z0c = orig.z - center.z;
  float y0c = orig.y - center.y;

  float a = (dir.y * dir.y * tan2) - dir.x * dir.x - dir.z * dir.z;
  float b = 2 * y0c * dir.y * tan2 - 2 * x0c * dir.x - 2 * z0c * dir.z;
  float c = tan2 * y0c * y0c - x0c * x0c - z0c * z0c;

  float delta = b * b - 4 * (a * c);

  if (delta < 0)
    return false;

  t0 = (-b - sqrt(delta)) / (2 * a);
  float t1 = (-b + sqrt(delta)) / (2 * a);

  if (t0 > t1)
    std::swap(t0, t1);

  if (t0 < 0) t0 = t1;

  if (t0 < 0) return false;

  Point3f hit = orig + t0 * dir;

  return center.y - hit.y > 0 and center.y - hit.y < height;
}

Vector3f Cone::normal(const Point3f &point) {
  float x = center.x;
  float z = center.z;
  float y = point.y - fabs((point.x - center.x) * tan);

  Point3f t(x, y, z);

  return glm::normalize(point - t);
}
