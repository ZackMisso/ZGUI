#include "button.h"

Button::Button() {
  // to be implemented
}

Button::Button(int xpos,int ypos,int width,int height) : GUIObject(xpos,ypos,width,height) {
  // to be implemented
}

Button::Button(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  // to be implemented
}

void Button::setClickFunc(void* param) { clickFunc = param; }
