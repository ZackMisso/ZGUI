#pragma once

// svg primitives are lines and curves. Currently the only curves are bezier curves

#include <glm/vec2.hpp>
#include "../dataStructures/rect.h"

using namespace glm;

class SVGPrimitive {
private:
public:
  SVGPrimitive();
  virtual void render() = 0;
  virtual vec2 getPosition() = 0;
  virtual rect getBB() = 0;
};
