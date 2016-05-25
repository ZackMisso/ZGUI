#include "checkbox.h"

Checkbox::Checkbox() {
  // to be implemented
}

Checkbox::Checkbox(int xpos,int ypos,int width,int height) : GUIObject(xpos,ypos,width,height) {
  // to be implemented
}

Checkbox::Checkbox(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  // to be implemented
}

bool Checkbox::getSelected() { return selected; }

void Checkbox::setSelected(bool param) { selected = param; }
void Checkbox::setPtr(bool* param) { ptr = param; }
