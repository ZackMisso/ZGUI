#pragma once

#include "guiObject.h"

class Checkbox : public GUIObject {
private:
public:
  Checkbox();
  Checkbox(int xpos,int ypos,int width,int height);
  Checkbox(int xpos,int ypos,int width,int height,int tabIndex);
};
