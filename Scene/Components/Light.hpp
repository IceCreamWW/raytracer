//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_LIGHT_HPP
#define MRAYTRACER_LIGHT_HPP

#include "Definitions.hpp"

class Light {
public:
  Light(const Vector3f &position, float intensity,  float attenuation);
  float intensity_at(Point3f hit);

  float intensity;
  float attenuation;
  Point3f position;
};

#endif // MRAYTRACER_LIGHT_HPP
