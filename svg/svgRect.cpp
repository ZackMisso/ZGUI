#include "svgRect.h"

SVGRect::SVGRect() {
  outlineColor = vec3(0);
  fillColor = vec3(0.0,0.0,1.0);
  selectedColor = fillColor;
  rounded = false;
  initRect();
}

SVGRect::~SVGRect() {
  // does nothing for know
}

void SVGRect::initRect() {
  // to be implemented
}

void SVGRect::render() {
  // to be implemented
}
