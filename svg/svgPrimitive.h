#pragma once

// svg primitives are lines and curves. Currently the only curves are bezier curves

#include <glm/vec2.hpp>
#include "../dataStructures/rect.h"

using namespace glm;

enum AlignmentType {
  ALIGNMENT_CENTER,
  ALIGNMENT_TOP_RIGHT,
  ALIGNMENT_TOP_LEFT,
  ALIGNMENT_BOT_RIGHT,
  ALIGNMENT_BOT_LEFT
};

class SVGPrimitive {
protected:
  AlignmentType alignment;
  rect bb;
  bool hasMoved;
public:
  SVGPrimitive();
  virtual void render() = 0;
  virtual void calculateBB() = 0;
  virtual void initializeBasic() = 0;
  vec2 getPosition();
  // getter methods
  rect getBB();
  // setter methods
  void setAlignment(AlignmentType param);
};
