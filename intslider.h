#pragma once

#include "slider.h"

class IntSlider : public Slider {
private:
public:
  IntSlider();
  IntSlider(int xpos,int ypos,int width,int height);
  IntSlider(int xpos,int ypos,int width,int height,int tabIndex);
};
