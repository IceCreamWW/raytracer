//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_MATERIAL_HPP
#define MRAYTRACER_MATERIAL_HPP

#include "Definitions.hpp"

class Material {

public:
  Material() {};
  Material(const Color &color, float ka, float kd, float ks, float n,
           float albedo, float opacity, float eta)
      : color(color), ka(ka), kd(kd), ks(ks), n(n), albedo(albedo),
        opacity(opacity), eta(eta) {}
  Color color;
  float ka;
  float kd;
  float ks;
  float n;
  float albedo;
  float opacity;
  float eta;
};

#endif // MRAYTRACER_MATERIAL_HPP
