#pragma once

#include "guiObject.h"

class Intbox : public GUIObject {
private:
  int val;
  int* ptr;
public:
  Intbox();
  Intbox(int xpos,int ypos,int width,int height);
  Intbox(int xpos,int ypos,int width,int height,int tabIndex);
  // getter methods
  int getVal();
  // setter methods
  void setVal(int param);
  void setPtr(int* param);
};
