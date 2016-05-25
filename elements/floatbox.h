#pragma once

#include "guiObject.h"

class Floatbox : public GUIObject {
private:
  float val;
  float* prt;
public:
  Floatbox();
  Floatbox(int xpos,int ypos,int width,int height);
  Floatbox(int xpos,int ypos,int width,int height,int tabIndex);
  // getter methods
  float getVal();
  // setter methods
  void setVal(float param);
  void setPrt(float* param);
};
