#pragma once

#include "beziercurve.h"

class QuadBezierCurve : public BezierCurve {
public:
  QuadBezierCurve();
  QuadBezierCurve(Array<vec2>* pts);
  virtual void evaluateCurve();
};
