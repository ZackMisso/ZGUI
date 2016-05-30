#pragma once

#include "svgPrimitive.h"
#include <glm/vec3.hpp>

class SVGLine : public SVGPrimitive {
private:
  vec2 first;
  vec2 second;
  vec3 firstColor;
  vec3 secondColor;
  float lineWidth;
public:
  SVGLine();
  SVGLine(vec2 one,vec2 two);
  virtual void render();
  virtual void calculateBB();
  virtual void initializeBasic();
  // getter methods
  vec2 getFirst();
  vec2 getSecond();
  vec3 getFirstColor();
  vec3 getSecondColor();
  float getLineWidth();
  // setter methods
  void setFirst(vec2 param);
  void setSecond(vec2 param);
  void setFirstColor(vec3 param);
  void setSecondColor(vec3 param);
  void setLineWidth(float param);
};
