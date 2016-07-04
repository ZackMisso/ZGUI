#pragma once

#include <glm/vec2.hpp>
#include "../datastructures/array.h"

using namespace glm;

class BezierCurve {
private:
  Array<vec2>* controlPoints;
  Array<vec2>* curve;
  bool continuous; // what is this used for?
  bool wrapAround; // both of these seem the same...
  bool dirty;
public:
  BezierCurve();
  BezierCurve(Array<vec2>* pts);
  ~BezierCurve();
  Array<vec2>* getCurve();
  void setProperties(bool wrap,bool cont);
  // class methods
  static void evaluateCurve(const Array<vec2>& ctrlPts,Array<vec2>* evaluatedPoints,const bool& wrap);
  static BezierCurve* createCurveAndCopy(Array<vec2>* control,Array<vec2>* pts);
  // getter methods
  Array<vec2>* getControlPoints() const;
  // setter methods
  void setControlPoints(Array<vec2>* param);
};
