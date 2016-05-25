#pragma once

#include "../dataStructures/array.h"
#include "../dataStructures/point2.h"

class BezierCurve {
private:
  Array<Point2>* controlPoints;
  bool continuous;
  bool wrapAround;
public:
  BezierCurve();
  BezierCurve(Array<Point2>* pts);
  ~BezierCurve();
  // getter methods
  Array<Point2>* getControlPoints();
  bool getContinuous();
  bool getWrapAround();
  // setter methods
  void setControlPoints(Array<Point2>* param);
  void setContinuous(bool param);
  void setWrapAround(bool param);
};
