#include "bezierCurve.h"

BezierCurve::BezierCurve() {
  controlPoints = new Array<vec2>();
  continuous = false;
  wrapAround = false;
}

BezierCurve::BezierCurve(Array<vec2>* pts) {
  controlPoints = pts;
  continuous = false;
  wrapAround = false;
}

Array<vec2>* BezierCurve::getControlPoints() { return controlPoints; }
bool BezierCurve::getContinuous() { return continuous; }
bool BezierCurve::getWrapAround() { return wrapAround; }

void BezierCurve::setControlPoints(Array<vec2>* param) { controlPoints = param; }
void BezierCurve::setContinuous(bool param) { continuous = param; }
void BezierCurve::setWrapAround(bool param) { wrapAround = param; }
