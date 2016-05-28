#pragma once

#include <glm/vec2.hpp>

using namespace glm;

struct rect {
  vec2 position; // bottom right
  vec2 dimension;
  rect() {
    position = vec2(0);
    dimension = vec2(0);
  }
  rect(vec2 p,vec2 d) {
    position = p;
    dimension = d;
  }
  rect(float x,float y,float w,float h) {
    position = vec2(x,y);
    dimension = vec2(w,h);
  }
};
