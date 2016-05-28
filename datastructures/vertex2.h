#pragma once

#include "point2.h"
#include <glm/vec2.cpp>
#include <glm/vec3.cpp>

using namespace glm;

class Vertex2 {
private:
  vec3 color;
  vec2 position;
public:
  Vertex2() {
    color = vec3();
    point = vec2();
  }

  Vertex2(vec2 p) {
    point = p;
    color = vec3();
  }

  Vertex2(vec2 p,vec3 c) {
    point = p;
    color = c;
  }

  // getter methods
  vec3 getColor() { return color; }
  vec2 getPoint() { return point; }
  
  // setter methods
  void setColor(vec3 param) { color = param; }
  void setPoint2(vec2 param) { point = param; }
};
