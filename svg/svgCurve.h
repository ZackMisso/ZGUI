#pragma once

#include "svgPrimitive.h"
#include "../dataStructures/bezierCurve.h"

class SVGCurve : public SVGPrimitive {
private:
  BezierCurve* curve;
public:
  SVGCurve();
  ~SVGCurve();
  virtual void render();
  virtual void calculateBB();
  virtual void initializeBasic();
  virtual void setUpRendering();
  // getter methods
  BezierCurve* getCurve();
  // setter methods
  void setCurve(BezierCurve* param);
};
