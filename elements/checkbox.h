#pragma once

#include "guiObject.h"

class Checkbox : public GUIObject {
private:
  bool selected;
  bool* ptr;
public:
  Checkbox();
  Checkbox(int xpos,int ypos,int width,int height);
  Checkbox(int xpos,int ypos,int width,int height,int tabIndex);
  // getter methods
  bool getSelected();
  // setter methods
  void setSelected(bool param);
  void setPtr(bool* param);
};
