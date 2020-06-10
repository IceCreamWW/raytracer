//
// Created by icecreamww on 2020/6/10.
//

#ifndef MRAYTRACER_IMAGE_HPP
#define MRAYTRACER_IMAGE_HPP

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <string>

typedef glm::vec3 Color;

using namespace std;

class Image {
public:
  int width;
  int height;
  glm::vec3 **pixels;

  Image(int width, int image);
  float aspect_ratio();
  void write_to_file(const string &filename);
  virtual ~Image();
};

#endif // MRAYTRACER_IMAGE_HPP
