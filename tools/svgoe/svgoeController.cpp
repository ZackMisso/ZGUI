#include "svgoeController.h"

SVGOEController() {
  objects = new Array<SVGObject*>();
  currentObj = 0;
}

~SVGOEController() {
  while(objects->getSize())
    objects->removeLast();
  delete objects;
}

int getCurrentObj() { return currentObj; }

void setCurrentObj(int param) { currentObj = param; }
