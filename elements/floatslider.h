#pragma once

#include "slider.h"

class FloatSlider : public Slider {
private:
  float min;
  float max;
  float val;
  float* prt;
public:
  FloatSlider();
  FloatSlider(int xpos,int ypos,int width,int height);
  FloatSlider(int xpos,int ypos,int width,int height,int tabIndex);
  // getter methods
  float getMin();
  float getMax();
  float getVal();
  // setter methods
  void setMin(float param);
  void setMax(float param);
  void setVal(float param);
  void setPtr(float* param);
};
