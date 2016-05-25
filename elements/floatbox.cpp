#include "floatbox.h"

Floatbox::Floatbox() {
  // to be implemented
}

Floatbox::Floatbox(int xpos,int ypos,int width,int height) : GUIObject(xpos,ypos,width,height) {
  // to be implemented
}

Floatbox::Floatbox(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  // to be implemented
}

float Floatbox::getVal() { return val; }

void Floatbox::setVal(float param) { val = param; }
void Floatbox::setPrt(float* param) { prt = param; }
