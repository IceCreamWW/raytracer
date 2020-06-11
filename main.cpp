#include "Object.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include <iostream>

int main() {
  float fov = M_PI / 3;
  Scene scene(1024, 768, fov, Vector3f(0.2, 0.7, 0.8));


  // Light *light = new Light(Point3f(-9, 14, -2), 1.4, 0.8);
  Light *light = new Light(Point3f(-20, 20, 20), 1.5, 0);
  scene.push(light);

  light = new Light(Point3f(30, 50, -25), 1.8, 0);
  scene.push(light);

  light = new Light(Point3f(30, 20, 30), 1.7, 0);
  scene.push(light);


  Sphere* sphere = nullptr;

  Material red_rubber(RED, 0, .15, 0.9f, .1f, 10);
  sphere = new Sphere(Point3f(1.5,-.5,-18), 3, red_rubber);
  scene.push(sphere);

  Material ivory(IVORY, 0, .15, 0.6f, .3f, 50);
  sphere = new Sphere(Point3f(-3,0,-16), 2, ivory);
  scene.push(sphere);

  scene.render();

  scene.write_to_file("test.ppm");
  return 0;
}



