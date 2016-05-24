#include "guiObject.h"

GUIObject::GUIObject() {
  xpos = 0;
  ypos = 0;
  width = 32;
  height = 32;
  tabIndex = -1;
  isShowing = true;
}

GUIObject::GUIObject(int x,int y,int w,int h) {
  xpos = x;
  ypos = y;
  width = w;
  height = h;
  tabIndex = -1;
  isShowing = true;
}

GUIObject::GUIObject(int x,int y,int w,int h,int tab) {
  xpos = x;
  ypos = y;
  width = w;
  height = h;
  tabIndex = tab;
  isShowing = true;
}

void GUIObject::render() {
  // to be extended
}

bool GUIObject::wasClicked(int x,int y) {
  // to be implemented
  return false;
}

void GUIObject::click() {
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

void GUIObject::setXpos(int param) { xpos = param; }
void GUIObject::setYpos(int param) { ypos = param; }
void GUIObject::setWidth(int param) { width = param; }
void GUIObject::setHeight(int param) { height = param; }
void GUIObject::setTabIndex(int param) { tabIndex = param; }
void GUIObject::setIsShowing(bool param) { isShowing = param; }
