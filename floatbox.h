#pragma once

#include "guiObject.h"

class Floatbox : public GUIObject {
private:
public:
  Floatbox();
  Floatbox(int xpos,int ypos,int width,int height);
  Floatbox(int xpos,int ypos,int width,int height,int tabIndex);
};
