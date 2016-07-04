#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include "../../shaderClasses/fragShader.h"
#include "../../shaderClasses/vertShader.h"

using namespace glm;

class SelectionRect {
private:
  FragShader* frag;
  VertShader* vert;
  GLuint program;
  vec3 color;
  vec2 origin;
  vec2 cursor;
  bool isOn;
public:
  SelectionRect();
  void updateColor(float r,float g,float b);
  void updateOrigin(float x,float y);
  void updateCursor(float x,float y);
  void turnOn();
  void turnOff();
  void render();
};
