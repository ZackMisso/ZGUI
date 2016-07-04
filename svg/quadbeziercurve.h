#pragma once

#include <glm/vec2.hpp>
#include "../datastructures/array.h"

using namespace glm;

class QuadBezierCurve {
private:
  Array<vec2>* controlPoints;
  Array<vec2>* curve;
  bool wrapAround;
  bool dirty;
public:
  QuadBezierCurve();
  QuadBezierCurve(Array<vec2>* pts);
  ~QuadBezierCurve();
  Array<vec2>* getCurve();
  // class methods
  static void evaluateCurve(const Array<vec2>& ctrlPts,Array<vec2>* evaluatePts,const bool& wrap);
  // setter methods
  void setControlPoints(Array<vec2>* param);
}
