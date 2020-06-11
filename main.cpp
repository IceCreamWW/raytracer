#include "Object.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include <iostream>

int main() {
  float fov = M_PI / 3;
  Scene scene(1024, 768, fov, Vector3f(0.2, 0.7, 0.8));


  // Light *light = new Light(Point3f(-9, 14, -2), 1.4, 0.8);
  Light *light = new Light(Point3f(-9, 8, -2), 2., 0.8);
  scene.push(light);

  Material red_rubber(RED, 0, .15, 0.9);
  auto *sphere = new Sphere(Point3f(-1,-.5,-10), 1, red_rubber);
  scene.push(sphere);

  Material ivory_rubber(IVORY, 0, .15, 0.7);
  sphere = new Sphere(Point3f(0,1,-14), 2, ivory_rubber);
  scene.push(sphere);

  scene.render();

  scene.write_to_file("test.ppm");
  return 0;
}



