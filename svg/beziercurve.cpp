#include "bezierCurve.h"

BezierCurve::BezierCurve() {
  controlPoints = new Array<Point2>();
  continuous = false;
  wrapAround = false;
}

BezierCurve::BezierCurve(Array<Point2>* pts) {
  controlPoints = pts;
  continuous = false;
  wrapAround = false;
}

Array<Point2>* BezierCurve::getControlPoints() { return controlPoints; }
bool BezierCurve::getContinuous() { return continuous; }
bool BezierCurve::getWrapAround() { return wrapAround; }

void BezierCurve::setControlPoints(Array<Point2>* param) { controlPoints = param; }
void BezierCurve::setContinuous(bool param) { continuous = param; }
void BezierCurve::setWrapAround(bool param) { wrapAround = param; }
