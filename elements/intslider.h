#pragma once

#include "slider.h"

class IntSlider : public Slider {
private:
  int min;
  int max;
  int val;
  int* ptr;
public:
  IntSlider();
  IntSlider(int xpos,int ypos,int width,int height);
  IntSlider(int xpos,int ypos,int width,int height,int tabIndex);
  // getter methods
  int getMin();
  int getMax();
  int getVal();
  // setter methods
  void setMin(int param);
  void setMax(int param);
  void setVal(int param);
  void setPtr(int* param);
};
