#pragma once

#include "../svg/svgo.h"

class GUIObject {
private:
  SVGObject* shape;
  int xpos;
  int ypos;
  int width;
  int height;
  int tabIndex;
  bool isShowing;
public:
  GUIObject();
  GUIObject(int xpos,int ypos,int width,int height);
  GUIObject(int xpos,int ypos,int width,int height,int tabIndex);
  // extendable methods
  virtual void render();
  virtual bool wasClicked(int x,int y);
  virtual void click(int x,int y);
  virtual void keyboard(char key);
  virtual bool wasHighlighted(int x,int y);
  virtual void highlight();
  // getter methods
  int getTabIndex();
  bool getIsShowing();
  // setter methods
  void setShape(SVGObject* object);
  void setXpos(int param);
  void setYpos(int param);
  void setWidth(int param);
  void setHeight(int param);
  void setTabIndex(int param);
  void setIsShowing(bool param);
};
