#pragma once

#include "guiObject.h"

class Intbox : public GUIObject {
private:
public:
  Intbox();
  Intbox(int xpos,int ypos,int width,int height);
  Intbox(int xpos,int ypos,int width,int height,int tabIndex);
};
