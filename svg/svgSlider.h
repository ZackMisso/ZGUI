#pragma once

#include "svgo.h"

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
