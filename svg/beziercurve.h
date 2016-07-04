#pragma once

#include "../dataStructures/array.h"
#include <glm/vec2.hpp>

using namespace glm;

class BezierCurve {
protected:
  Array<vec2>* controlPoints;
  Array<vec2>* curve;
  bool continuous;
  bool wrapAround;
  bool dirty;
public:
  BezierCurve();
  BezierCurve(Array<vec2>* pts);
  ~BezierCurve();
  void setProperties(bool wrap,bool cont);
  virtual void evaluateCurve() = 0;
  Array<vec2>* getCurve();
  // class methods
  static void copyIntoCurve(const Array<vec2>* control,const Array<vec2>* pts,BezierCurve* bCurve);
  // getter methods
  Array<vec2>* getControlPoints();
  // setter methods
  void setControlPoints(Array<vec2>* param);
};
