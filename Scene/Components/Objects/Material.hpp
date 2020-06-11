//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_MATERIAL_HPP
#define MRAYTRACER_MATERIAL_HPP

#include "Definitions.hpp"

class Material {

public:
  Material() {};
  Material(const Color &color, float opacity, float ka, float kd, float ks,
           float n, float albedo)
      : color(color), opacity(opacity), ka(ka), kd(kd), ks(ks), n(n),
        albedo(albedo) {}
  Color color;
  float opacity;
  float ka;
  float kd;
  float ks;
  float n;
  float albedo;
};

#endif // MRAYTRACER_MATERIAL_HPP
