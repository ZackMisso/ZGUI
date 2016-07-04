#pragma once

// arbitrary bezier curve representation

#include "beziercurve.h"

class ArbBezierCurve : public BezierCurve {
public:
  ArbBezierCurve();
  ArbBezierCurve(Array<vec2>* pts);
  virtual void evaluateCurve();
};
