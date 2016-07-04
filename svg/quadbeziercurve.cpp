#include "quadbeziercurve.h"

QuadBezierCurve::QuadBezierCurve() {
  // to be implemented
}

QuadBezierCurve::QuadBezierCurve(Array<vec2>* pts) {
  // to be implemented
}

QuadBezierCurve::~QuadBezierCurve() {
  // to be implemented
}

Array<vec2>* QuadBezierCurve::getCurve() {
  // to be implemented
  return 0x0;
}

void QuadBezierCurve::evaluateCurve(const Array<vec2>& ctrlPts,Array<vec2>& evaluatedPts,const bool& wrap) {
  // to be implemented
}

QuadBezierCurve* QuadBezierCurve::createCurveAndCopy(Array<vec2>* control,Array<vec2>* pts) {
  QuadBezierCurve* newCurve = new QuadBezierCurve();
  for(int i=0;i<control->getSize();i++) newCurve->controlPoints->add(control->get(i));
  for(int i=0;i<pts->getSize();i++) newCurve->curve->add(pts->get(i));
  return newCurve;
}

void QuadBezierCurve::setControlPoints(Array<vec2>* param) { controlPoints = param; }
