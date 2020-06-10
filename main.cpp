#include "Scene/Image.hpp"
#include "Scene/Scene.hpp"
#include "Shapes/Sphere.hpp"
#include <Color.hpp>
#include <iostream>

int main() {
  float fov = M_PI / 3;
  Scene scene(1024, 768, fov);

  auto *sphere = new Sphere(Point3f(-1,-.5,-8), 1, RED);
  scene.push(sphere);

  sphere = new Sphere(Point3f(0,1,-12), 2, IVORY);
  scene.push(sphere);


  scene.render();

  scene.write_to_file("test.ppm");
  return 0;
}



