#include "svgCurve.h"

SVGCurve::SVGCurve() {
  curve = new BezierCurve();
}

SVGCurve::~SVGCurve() {
  delete curve;
}

void SVGCurve::render() {
  // to be implemented
}

vec2 SVGCurve::getPosition() {
  // to be implemented
  return vec2();
}

void SVGCurve::calculateBB() {
  // to be implemented
  bb = rect();
  hasMoved = false;
}

void SVGCurve::initializeBasic() {
  curve->getControlPoints()->add(vec2(-0.25,0));
  curve->getControlPoints()->add(vec2(0.25,0));
  curve->setWrapAround(true);
  curve->setContinuous(true);
}

BezierCurve* SVGCurve::getCurve() { return curve; }

void SVGCurve::setCurve(BezierCurve* param) { curve = param; }
