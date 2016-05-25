#include "intslider.h"

IntSlider::IntSlider() {
  // to be implemented
}

IntSlider::IntSlider(int xpos,int ypos,int width,int height) : GUIObject(xpos,ypos,width,height) {
  // to be implemented
}

IntSlider::IntSlider(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  // to be implemented
}

int IntSlider::getMin() { return min; }
int IntSlider::getMax() { return max; }
int IntSlider::getVal() { return val; }

void IntSlider::setMin(int param) { min = param; }
void IntSlider::setMax(int param) { max = param; }
void IntSlider::setVal(int param) { val = param; }
void IntSlider::setPtr(int* param) { ptr = param; }
