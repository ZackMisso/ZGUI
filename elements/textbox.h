#pragma once

#include "guiObject.h"

class Textbox : public GUIObject {
private:
public:
  Textbox();
  Textbox(int xpos,int ypos,int width,int height);
  Textbox(int xpos,int ypos,int width,int height,int tabIndex);
};
