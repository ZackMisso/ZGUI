#pragma once

#include "slider.h"

class FloatSlider : public Slider {
private:
public:
  FloatSlider();
  FloatSlider(int xpos,int ypos,int width,int height);
  FloatSlider(int xpos,int ypos,int width,int height,int tabIndex);
};
