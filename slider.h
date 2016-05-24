#pragma once

#include "guiObject.h"

class Slider : public GUIObject {
private:
public:
  Slider();
  Slider(int xpos,int ypos,int width,int height);
  Slider(int xpos,int ypos,int width,int height,int tabIndex);
};
