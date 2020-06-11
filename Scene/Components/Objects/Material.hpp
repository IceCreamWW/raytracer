//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_MATERIAL_HPP
#define MRAYTRACER_MATERIAL_HPP

#include "Definitions.hpp"

class Material {

public:
  Material() {};
  Material(const Color &color, float opacity, float ka, float kd)
      : color(color), opacity(opacity), ka(ka), kd(kd) {}
  Color color;
  float opacity;
  float ka;
  float kd;
};

#endif // MRAYTRACER_MATERIAL_HPP
