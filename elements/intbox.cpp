#include "intbox.h"

Intbox::Intbox() {
  // to be implemented
}

Intbox::Intbox(int xpos,int ypos,int width,int height) : GUIObject(xpos,ypos,width,height) {
  // to be implemented
}

Intbox::Intbox(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  // to be implemented
}

int Intbox::getVal() { return val; }

void Intbox::setVal(int param) { val = param; }
void Intbox::setPtr(int* param) { ptr = param; }
