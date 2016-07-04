#include "cubicbeziercurve.h"

CubicBezierCurve::CubicBezierCurve() {
  // to be implemented
}

CubicBezierCurve::CubicBezierCurve(Array<vec2>* pts) {
  // to be implemented
}

CubicBezierCurve::~CubicBezierCurve() {
  // to be implemented
}

Array<vec2>* CubicBezierCurve::getCurve() {
  // to be implemented
  return 0x0;
}

void CubicBezierCurve::evaluatedCurve(const Array<vec2>& ctrlPts,Array<vec2>* evaluatedPts,const bool& wrap) {
  // to be implemented
}

CubicBezierCurve* CubicBezierCurve::crreateCurveAndCopy(Array<vec2>* control,Array<vec2>* pts) {
  CubicBezierCurve* newCurve = new CubicBezierCurve();
  for(int i=0;i<control->getSize();i++) newCurve->controlPoints->add(control->get(i));
  for(int i=0;i<pts->getSize();i++) newCurve->curve->add(pts->get(i));
  return newCurve;
}

void CubicBezierCurve::setControlPoints(Array<vec2>* param) { controlPoints = param; }
