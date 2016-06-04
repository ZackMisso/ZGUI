#pragma once

#include <glm/vec2.hpp>
#include "array.h"

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
  // class methods
  static evaluateCurve(const Array<vec2>& ctrlPts,Array<vec2>* evaluatedPoints,const bool& wrap) const;
  // getter methods
  Array<vec2>* getControlPoints() const;
  bool getContinuous() const;
  bool getWrapAround() const;
  // setter methods
  void setControlPoints(Array<vec2>* param);
  void setContinuous(bool param);
  void setWrapAround(bool param);
};
