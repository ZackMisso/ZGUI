#include "selectionRect.h"

SelectionRect::SelectionRect() {
  frag = new FragShader();
  vert = new VertShader();
  color = vec3(0.0f,0.0f,1.0f);
  origin = vec2(0.0f,0.0f);
  cursor = vec2(0.0f,0.0f);
  isOn = false;
}

SelectionRect::~SelectionRect() {
  delete frag;
  delete vert;
}

void SelectionRect::render() {
  // to be implemented
}

void SelectionRect::updateColor(float r,float g,float b) {
  color = vec3(r,g,b);
}

void SelectionRect::updateOrigin(float x,float y) {
  origin = vec2(x,y);
}

void SelectionRect::updateCursor(float x,float y) {
  cursor = vec2(x,y);
}

void SelectionRect::turnOn() {
  isOn = true;
}

void SelectionRect::turnOff() {
  isOn = false;
}
