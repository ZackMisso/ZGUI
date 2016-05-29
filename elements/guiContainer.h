#pragma once

#include "guiObject.h"

class GUIContainer : public GUIObject {
private:
  Array<GUIObject*>* objects;
public:
  GUIContainer();
  GUIContainer(int xpos,int ypos,int width,int height);
  GUIContainer(int xpos,int ypos,int width,int height,int tabIndex);
  ~GUIContainer();
  virtual void render();
  virtual void click(int x,int y);
  // getter methods
  Array<GUIObject*>* getObjects();
  // setter methods
  void setObjects(Array<GUIObject*>* param);
};
