#pragma once

#include "guiObject.h"

class Button : public GUIObject {
private:
  void* clickFunc;
public:
  Button();
  Button(int xpos,int ypos,int width,int height);
  Button(int xpos,int ypos,int width,int height,int tabIndex);
  // setter methods
  void setClickFunc(void* param);
};
