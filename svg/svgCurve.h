#pragma once

#include "svgPrimitive.h"
#include "../dataStructures/bezierCurve.h"

class SVGCurve : SVGPrimitive {
private:
  BezierCurve* curve;
public:
  SVGCurve();
  ~SVGCurve();
  virtual void render();
  virtual vec2 getPosition();
  virtual rect getBB();
  // getter methods
  BezierCurve* getCurve();
  // setter methods
  void setCurve(BezierCurve* param);
};
