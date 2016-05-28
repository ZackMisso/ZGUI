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

rect SVGCurve::getBB() {
  // to be implemented
  return rect();
}

BezierCurve* SVGCurve::getCurve() { return curve; }

void SVGCurve::setCurve(BezierCurve* param) { curve = param; }
