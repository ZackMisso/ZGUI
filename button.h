#pragma once

#include "guiObject.h"

class Button : public GUIObject {
private:
public:
  Button();
  Button(int xpos,int ypos,int width,int height);
  Button(int xpos,int ypos,int width,int height,int tabIndex);
};
