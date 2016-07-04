#include "beziercurve.h"

BezierCurve::BezierCurve() {
  controlPoints = new Array<vec2>();
  curve = new Array<vec2>();
  continuous = true;
  wrapAround = true;
  dirty = true;
}

BezierCurve::BezierCurve(Array<vec2>* pts) {
  controlPoints = pts;
  curve = new Array<vec2>();
  continuous = true;
  wrapAround = true;
  dirty = true;
}

BezierCurve::~BezierCurve() {
  delete controlPoints;
  delete curve;
}

Array<vec2>* BezierCurve::getCurve() {
  if(dirty) {
    evaluateCurve();
    dirty = false;
  }
  return curve;
}

void BezierCurve::setProperties(bool wrap,bool cont) {
  wrapAround = wrap;
  continuous = cont;
}

void BezierCurve::copyIntoCurve(const Array<vec2>* control,const Array<vec2>* pts,BezierCurve* bCurve) {
  bCurve->controlPoints->clear();
  bCurve->curve->clear();
  for(int i=0;i<control->getSize();i++) bCurve->controlPoints->add(control->get(i));
  for(int i=0;i<pts->getSize();i++) bCurve->curve->add(pts->get(i));
}

Array<vec2>* BezierCurve::getControlPoints() { return controlPoints; }

void BezierCurve::setControlPoints(Array<vec2>* param) { controlPoints = param; }
