#include "floatslider.h"

FloatSlider::FloatSlider() {
  // to be implemented
}

FloatSlider::FloatSlider(int xpos,int ypos,int width,int height) : GUIObject(xpos,ypos,width,height) {
  // to be implemented
}

FloatSlider::FloatSlider(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  // to be implemented
}

float FloatSlider::getMin() { return min; }
float FloatSlider::getMax() { return max; }
float FloatSlider::getVal() { return val; }

void FloatSlider::setMin(float param) { min = param; }
void FloatSlider::setMax(float param) { max = param; }
void FloatSlider::setVal(float param) { val = param; }
void FloatSlider::setPtr(float* param) { ptr = param; }
