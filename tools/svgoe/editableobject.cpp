#include "editableobject.h"

EditableObject::EditableObject() {
  selectedPoints = new Array<vec2>();
  selectedFrag = new FragShader();
  selectedVert = new VertShader();
}

EditableObject::~EditableObject() {
  while(selectedPoints->getSize) selectedPoints->removeLast();
  delete selectedPoints;
  delete selectedFrag;
  delete selectedVert;
}

void EditableObject::render() {
  renderLocal();
  // to be implemented
}
