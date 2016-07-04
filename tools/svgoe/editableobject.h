#pragma once

#include "../../datastructures/array.h"
#include "../../shaderClasses/fragShader.h"
#include "../../shaderClasses/vertShader.h"
#include "selectionRect.h"

class EditableObject {
protected:
  Array<vec2>* selectedPoints;
  FragShader* selectedFrag;
  VertShader* selectedVert;
  GLuint program;
  
  virtual void renderLocal() = 0;
public:
  EditableObject();
  ~EditableObject();
  virtual void takeInMouseClick(double x,double y) = 0;
  virtual void takeInSelectionRect(const SelectionRect* rect) = 0;
  virtual void takeInKey(int key) = 0;
  void render();
};
