#pragma once

#include <glm/vec2.hpp>
#include "array.h"

using namespace glm;

class BezierCurve {
private:
  Array<vec2>* controlPoints;
  bool continuous;
  bool wrapAround;
public:
  BezierCurve();
  BezierCurve(Array<vec2>* pts);
  ~BezierCurve();
  // getter methods
  Array<vec2>* getControlPoints();
  bool getContinuous();
  bool getWrapAround();
  // setter methods
  void setControlPoints(Array<vec2>* param);
  void setContinuous(bool param);
  void setWrapAround(bool param);
};
