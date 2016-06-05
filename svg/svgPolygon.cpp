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

void SVGPolygon::calculateBB() {
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

void SVGPolygon::initializeBasic() {
  points->add(vec2(0.25,0.25));
  points->add(vec2(0.25,-0.25));
  points->add(vec2(-0.25,-0.25));
  points->add(vec2(-0.25,0.25));
  hasMoved = true;
}

void SVGPolygon::setUpRendering() {
  // to be implemented
}

Array<vec2>* SVGPolygon::getPoints() { return points; }
vec3 SVGPolygon::getColor() { return color; }

void SVGPolygon::setPoints(Array<vec2>* param) { points = param; }
void SVGPolygon::setColor(vec3 param) { color = param; }
