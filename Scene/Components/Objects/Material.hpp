//
// Created by icecreamww on 2020/6/11.
//

#ifndef MRAYTRACER_MATERIAL_HPP
#define MRAYTRACER_MATERIAL_HPP

#include "Definitions.hpp"

class Material {

public:
  Material() {};
  Material(const Color &color, float ka, float kd, float ks,
           float n, float albedo, float refractiveIndex)
      : color(color), ka(ka), kd(kd), ks(ks), n(n),
        albedo(albedo), refractive_index(refractiveIndex) {}
  Color color;
  float ka;
  float kd;
  float ks;
  float n;
  float albedo;
  float refractive_index;
};

#endif // MRAYTRACER_MATERIAL_HPP
