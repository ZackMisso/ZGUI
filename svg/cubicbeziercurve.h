#pragma once

#include "beziercurve.h"

class CubicBezierCurve : public BezierCurve {
public:
  CubicBezierCurve();
  CubicBezierCurve(Array<vec2>* pts);
  virtual void evaluateCurve();
};
