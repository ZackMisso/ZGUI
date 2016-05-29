#include "svgRect.h"

SVGRect::SVGRect() {
  outlineColor = vec3(0);
  fillColor = vec3(0.0f,0.0f,1.0f);
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
