#pragma once

#include <glm/vec3.hpp>
#include "svgPrimitive.h"
#include "../dataStructures/array.h"

class SVGPolygon : public SVGPrimitive {
private:
  Array<vec2>* points;
  vec3 color;
public:
  SVGPolygon();
  ~SVGPolygon();
  virtual void render();
  virtual vec2 getPosition();
  virtual rect calculateBB();
  virtual void initializeBasic();
  // getter methods
  Array<vec2>* getPoints();
  vec3 getColor();
  // setter methods
  void setPoints(Array<vec2>* param);
  void setColor(vec3 param);
};
