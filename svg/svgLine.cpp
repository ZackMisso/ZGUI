#include "svgLine.h"

SVGLine::SVGLine() {
  first = vec2();
  second = vec2();
  firstColor = vec3(1);
  secondColor = vec3(1);
  lineWidth = 1;
}

SVGLine::SVGLine(vec2 one,vec2 two) {
  first = one;
  second = two;
  firstColor = vec3(1);
  secondColor = vec3(1);
  lineWidth = 1;
}

void SVGLine::render() {
  // to be implemented
}

vec2 SVGLine::getPosition() {
  // to be implemented
  return vec2();
}

void SVGLine::calculateBB() {
  // to be implemented
  bb = rect();
  hasMoved = false;
}

void SVGLine::initializeBasic() {
  first = vec2(-0.25,0);
  second = vec2(0.25,0);
  lineWidth = 1;
}

vec2 SVGLine::getFirst() { return first; }
vec2 SVGLine::getSecond() { return second; }
vec3 SVGLine::getFirstColor() { return firstColor; }
vec3 SVGLine::getSecondColor() { return secondColor; }
float SVGLine::getLineWidth() { return lineWidth; }

void SVGLine::setFirst(vec2 param) { first = param; }
void SVGLine::setSecond(vec2 param) { second = param; }
void SVGLine::setFirstColor(vec3 param) { firstColor = param; }
void SVGLine::setSecondColor(vec3 param) { secondColor = param; }
void SVGLine::setLineWidth(float param) { lineWidth = param; }
