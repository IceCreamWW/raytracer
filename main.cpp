#include "Cylinder.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Cone.hpp"
#include "Plane.hpp"
#include <iostream>

void push_cone(Scene *scene, const Point3f &center, float radius,
                   float height, const Material &material) {
  Cone *cone = nullptr;
  Circle* circle = nullptr;

  cone = new Cone(center, radius, height, material);
  scene->push(cone);

  circle = new Circle(center - Vector3f(0,height,0), radius, Vector3f(0,-1,0), material);
  scene->push(circle);
}

void push_cylinder(Scene *scene, const Point3f &center, float radius,
                   float height, const Material &material) {
  Cylinder *cylinder = nullptr;
  Circle* circle = nullptr;

  cylinder = new Cylinder(center, radius, height, material);
  scene->push(cylinder);

  circle = new Circle(center + Point3f(0, height, 0), radius, Vector3f(0,1,0), material);
  scene->push(circle);

  circle = new Circle(center, radius, Vector3f(0,-1,0), material);
  scene->push(circle);
}

void push_pyramid(Scene *scene, const Point3f &a, const Point3f &b,
                  const Point3f &c, const Point3f &d, Point3f e,
                  const Material &material) {
  Point3f center = (a + b + c + d + e) / 5.f;
  Triangle *triangle = nullptr;
  triangle = new Triangle(a, b, c, center, material);
  scene->push(triangle);

  triangle = new Triangle(a, c, d, center, material);
  scene->push(triangle);

  triangle = new Triangle(e, a, b, center, material);
  scene->push(triangle);

  triangle = new Triangle(e, b, c, center, material);
  scene->push(triangle);

  triangle = new Triangle(e, c, d, center, material);
  scene->push(triangle);

  triangle = new Triangle(e, d, a, center, material);
  scene->push(triangle);
}

int main() {
  float fov = M_PI * 2 / 3;

  Scene scene(1920, 1080, fov, Vector3f(0.2, 0.7, 0.8), 0.7);
//  Scene scene(800, 600, fov, Vector3f(0.2, 0.7, 0.8), 0.7);
  Image *pixelmap = new Image();
  pixelmap->read_from_file("envmap.ppm");
  scene.set_pixel_map(pixelmap);

  // Light *light = new Light(Point3f(-9, 14, -2), 1.4, 0.8);
  Light *light = nullptr;

  light = new Light(Point3f(-20, 20, 20), 1.5, 0);
  scene.push(light);
//
  light = new Light(Point3f(30, 50, -25), 1.8, 0);
  scene.push(light);

  light = new Light(Point3f(30, 20, 30), 1.7, 0);
  scene.push(light);

  Sphere *sphere = nullptr;
  Triangle *triangle = nullptr;

  Point3f a, b, c, d, e, center;

  Material red_rubber(RED, 1, 0.9f, .1f, 10, 0.1, 0, 0);
  Material ivory(IVORY, .15, 0.6f, .3f, 50, 0.3, 0, 0);
  Material mirror(WHITE, .0, .0f, 10.f, 1450, 0.9, 0, 0);
  Material glass(Color(0.6, 0.7, 0.8), 0, .0f, .5f, 125, 0.1, 0.8, 1.3f);

//  Material red_rubber(RED, 1, 0.9f, .0f, 10, 0.0, 0, 0);
//  Material ivory(IVORY, 1, 0.6f, .0f, 50, 0.0, 0, 0);
//  Material mirror(WHITE, 1, .0f, 0.f, 1450, 0.0, 0, 0);
//  Material glass(Color(0.6, 0.7, 0.8), 1, .0f, .0f, 125, 0.0, 0.0, 1.5f);


  sphere = new Sphere(Point3f(2.5, -.5, -19), 3.5, red_rubber);
  scene.push(sphere);

  sphere = new Sphere(Point3f(-2.5, 1.8, -11), 1.5, ivory);
  scene.push(sphere);

  sphere = new Sphere(Point3f(3.f, 10, -23), 5.4, mirror);
  scene.push(sphere);
//
  sphere = new Sphere(Point3f(-1.f, 0.0, -8), 1.0, glass);
  scene.push(sphere);

  a = Point3f(-4.5, -1, -10);
  b = Point3f(-3.5, -1, -10);
  c = Point3f(-2.5, -1, -6);
  d = Point3f(-4.5, -1, -6);
  e = Point3f(-3.5, 2, -8);
  push_pyramid(&scene, a, b, c, d, e, ivory);

  push_cylinder(&scene, Point3f(7.5, -2, -14), 1.3, 7, glass);
//  push_cylinder(&scene, Point3f(5, -2, -19), 1, 5, orange_rubber);
//  push_cylinder(&scene, Point3f(-5, -2, -10), 1, 5, orange_rubber);
//  push_cylinder(&scene, Point3f(5, -2, -10), 1, 5, orange_rubber);

  push_cone(&scene, Point3f(14, 3, -19), 2, 5, red_rubber);
  scene.render();

  scene.write_to_file("test.ppm");
  return 0;
}
