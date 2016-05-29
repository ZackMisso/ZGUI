#include "svgPolygon.h"

SVGPolygon::SVGPolygon() {
  points = new Array<vec2>();
  color = vec3(1);
}

SVGPolygon::~SVGPolygon(){
  while(points->getSize())
    points->removeLast();
  delete points;
}

void SVGPolygon::render() {
  // to be implemented
}

vec2 SVGPolygon::getPosition() {
  // to be implemented
  return vec2();
}

rect SVGPolygon::getBB() {
  // to be implemented
  return rect();
}

Array<vec2>* SVGPolygon::getPoints() { return points; }
vec3 SVGPolygon::getColor() { return color; }

void SVGPolygon::setPoints(Array<vec2>* param) { points = param; }
void SVGPolygon::setColor(vec3 param) { color = param; }
