//
// Created by icecreamww on 2020/6/10.
//

#include "Image.hpp"
#include <fstream>

Image::Image(int width, int height) : width(width), height(height) {
  create_image(width, height);
}

Image::~Image() {
  for (int i = 0; i < height; ++i) {
    delete[] pixels[i];
  }
  delete[] pixels;
}


void Image::write_to_file(const string& filename) {
  std::ofstream ofs;
  ofs.open(filename);
  ofs << "P6\n" << width << " " << height << "\n255\n";
  for (size_t i = 0; i < height; ++i)
    for (size_t j = 0; j < width; ++j)
      for (size_t c = 0; c < 3; ++c)
        ofs << (char)(255 * std::max(0.f, std::min(1.f, pixels[i][j][c])));
  ofs.close();
}
void Image::read_from_file(const string &filename) {
  std::ifstream ifs;
  ifs.open(filename, ios::binary);
  string t;
  int a;
  unsigned char x;
  ifs >> t >> width >> height >> t;
  ifs.read(reinterpret_cast<char*>(&x), 1) ;

  create_image(width, height);
  for (size_t i = 0; i < height; ++i)
    for (size_t j = 0; j < width; ++j)
      for (size_t c = 0; c < 3; ++c) {
        ifs.read(reinterpret_cast<char*>(&x), 1) ;
        pixels[i][j][c] = x / 255.;
      }
  ifs.close();
}

void Image::create_image(int width, int heigth) {
  pixels = new glm::vec3 *[height];
  for (int i = 0; i < height; ++i) {
    pixels[i] = new glm::vec3[width];
    for (int j = 0; j < width; ++j) {
      pixels[i][j] = Color(0.0f);
    }
  }
}
