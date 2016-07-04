#include "svgCurve.h"
#include "arbbeziercurve.h"

SVGCurve::SVGCurve() {
  curve = new ArbBezierCurve();
}

SVGCurve::~SVGCurve() {
  delete curve;
}

void SVGCurve::render() {
  Array<vec2>* pts = curve->getCurve();

  // to be implemented
}

void SVGCurve::calculateBB() {
  Array<vec2>* points = curve->getControlPoints();
  float maxX = -100.0f;
  float maxY = -100.0f;
  float minX = 100.0f;
  float minY = 100.0f;
  for(int i=0;i<points->getSize();i++) {
    if(points->get(i).x > maxX) maxX = points->get(i).x;
    if(points->get(i).y > maxY) maxY = points->get(i).y;
    if(points->get(i).x < minX) minX = points->get(i).x;
    if(points->get(i).y < minY) minY = points->get(i).y;
  }
  bb = rect(minX,minY,maxX-minX,maxY-minY);
  hasMoved = false;
}

void SVGCurve::initializeBasic() {
  curve->getControlPoints()->add(vec2(-0.25,0));
  curve->getControlPoints()->add(vec2(0.25,0));
  curve->setProperties(true,true);
}

void SVGCurve::setUpRendering() {
  // to be implemented
}

BezierCurve* SVGCurve::getCurve() { return curve; }

void SVGCurve::setCurve(BezierCurve* param) { curve = param; }
