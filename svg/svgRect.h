#pragma once

#include "svgo.h"
#include <glm/vec3.hpp>

using namespace glm;

class SVGRect : public SVGObject {
private:
  vec3 outlineColor;
  vec3 fillColor;
  vec3 selectedColor;
  bool rounded;
  void initRect();
public:
  SVGRect();
  ~SVGRect();
  virtual void render();
};
