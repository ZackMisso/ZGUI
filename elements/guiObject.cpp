#include "guiObject.h"

GUIObject::GUIObject() {
  shape = 0x0;
  xpos = 0;
  ypos = 0;
  width = 32;
  height = 32;
  tabIndex = -1;
  isShowing = true;
}

GUIObject::GUIObject(int x,int y,int w,int h) {
  shape = 0x0;
  xpos = x;
  ypos = y;
  width = w;
  height = h;
  tabIndex = -1;
  isShowing = true;
}

GUIObject::GUIObject(int x,int y,int w,int h,int tab) {
  shape = 0x0;
  xpos = x;
  ypos = y;
  width = w;
  height = h;
  tabIndex = tab;
  isShowing = true;
}

GUIObject::~GUIObject() {
  delete shape;
}

void GUIObject::render() {
  // to be extended
}

bool GUIObject::wasClicked(int x,int y) {
  // to be implemented
  return false;
}

void GUIObject::click(int x,int y) {
  // to be extended
}

void GUIObject::keyboard(char key) {
  // to be extended
}

bool GUIObject::wasHighlighted(int x,int y) {
  // to be implemented
  return false;
}

void GUIObject::highlight() {
  // to be extended
}

int GUIObject::getTabIndex() { return tabIndex; }
bool GUIObject::getIsShowing() { return isShowing; }

void GUIObject::setShape(SVGObject* param) { shape = param; }
void GUIObject::setXpos(int param) { xpos = param; }
void GUIObject::setYpos(int param) { ypos = param; }
void GUIObject::setWidth(int param) { width = param; }
void GUIObject::setHeight(int param) { height = param; }
void GUIObject::setTabIndex(int param) { tabIndex = param; }
void GUIObject::setIsShowing(bool param) { isShowing = param; }
