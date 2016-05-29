#pragma once

#include "svgo.h"
#include <glm/vec3.hpp>

using namespace glm;

class SVGSlider : public SVGObject {
private:
  vec3 lineColor;
  vec3 sliderKnobColor;
  vec3 sliderKnobOutlineColor;
  void initSlider();
public:
  SVGSlider();
  ~SVGSlider();
  virtual void render();
};
