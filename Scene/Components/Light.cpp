//
// Created by icecreamww on 2020/6/11.
//

#include "Light.hpp"
#include <algorithm>
Light::Light(const Vector3f &position, float intensity, float attenuation)
    : intensity(intensity), attenuation(attenuation), position(position) {}


float Light::intensity_at(Point3f hit) {
  float distance = glm::distance(position, hit);
  float intensity_at_hit = 1 / pow(distance, attenuation) * intensity;
  return std::min(intensity_at_hit, intensity);
}
