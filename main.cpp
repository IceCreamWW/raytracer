#include "Object.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include <iostream>

int main() {
  float fov = M_PI / 2;
  Scene scene(1024, 768, fov, Vector3f(0.2, 0.7, 0.8));
//  Scene scene(1024, 768, fov);


  // Light *light = new Light(Point3f(-9, 14, -2), 1.4, 0.8);
  Light *light = new Light(Point3f(-20, 20, 20), 1.5, 0);
  scene.push(light);

  light = new Light(Point3f(30, 50, -25), 1.8, 0);
  scene.push(light);

  light = new Light(Point3f(30, 20, 30), 1.7, 0);
  scene.push(light);


  Sphere* sphere = nullptr;

  Material red_rubber(RED, .15, 0.9f, .1f, 10, 0.1, 0, 0);
  Material ivory(IVORY, .15, 0.6f, .3f, 50, 0.3, 0, 0);
  Material mirror(WHITE, .0, .0f, 10.f, 1450, 0.9, 0, 0);
  Material glass(Color(0.6, 0.7, 0.8),0, .0f, .5f, 125, 0.1, 0.8, 1.5f);


  sphere = new Sphere(Point3f(1.5,-.5,-18), 3, red_rubber);
  scene.push(sphere);

  sphere = new Sphere(Point3f(-3.5,0,-16), 2, ivory);
  scene.push(sphere);

  sphere = new Sphere(Point3f(7,5,-18), 4, mirror);
  scene.push(sphere);

  sphere = new Sphere(Point3f(-1.0, -1.5, -12), 2, glass);
  scene.push(sphere);


  scene.render();

  scene.write_to_file("test.ppm");
  return 0;
}



