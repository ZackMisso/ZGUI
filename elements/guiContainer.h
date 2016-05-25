#pragma once

#include "guiObject.h"

class GUIContainer : public GUIObject {
private:
public:
  GUIContainer();
  GUIContainer(int xpos,int ypos,int width,int height);
  GUIContainer(int xpos,int ypos,int width,int height,int tabIndex);
};
