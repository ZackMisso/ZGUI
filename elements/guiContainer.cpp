#include "guiContainer.h"

GUIContainer::GUIContainer() : GUIObject() {
  objects = new Array<GUIObject*>();
}

GUIContainer::GUIContainer(int xpos,int ypos,int width,int height) GUIObject(xpos,ypos,width,height) {
  objects = new Array<GUIObject*>();
}

GUIContainer::GUIContainer(int xpos,int ypos,int width,int height,int tabIndex) : GUIObject(xpos,ypos,width,height,tabIndex) {
  objects = new Array<GUIObject*>();
}

GUIContainer::~GUIContainer() {
  while(objects->getSize())
    delete objects->removeLast();
  delete objects;
}

void GUIContainer::render() {
  // to be implemented
  for(int i=0;i<objects->getSize();i++)
    objects->get(i)->render();
}

void GUIContainer::click(int x,int y) {
  // ,aybe implement more
  for(int i=0;i<objects->getSize();i++)
    if(objects->get(i)->wasClicked(x,y)) {
      objects->get(i)->click(x,y);
      i=objects->getSize();
    }
}

Array<GUIObject*>* GUIContainer::getObjects() { return objects; }

void GUIContainer::setObjects(Array<GUIObject*>* param) { objects = param; }
