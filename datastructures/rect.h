#pragma once

#include <glm/vec2.hpp>

using namespace glm;

struct rect {
  vec2 pos; // bottom right
  vec2 dim;
  rect() {
    pos = vec2(0);
    dim = vec2(0);
  }
  rect(vec2 p,vec2 d) {
    pos = p;
    dim = d;
  }
  rect(float x,float y,float w,float h) {
    pos = vec2(x,y);
    dim = vec2(w,h);
  }
};
