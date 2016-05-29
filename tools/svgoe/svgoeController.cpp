#include "svgoeController.h"

SVGOEController::SVGOEController() {
  objects = new Array<SVGObject*>();
  currentPrimitives = new Array<SVGPrimitive*>();
  currentObj = 0;
  currentPrimitive = 0;
  mouseX = 0.0;
  mouseY = 0.0;
  editMode = EMPTY;
}

SVGOEController::~SVGOEController() {
  while(objects->getSize())
    delete objects->removeLast();
  while(currentPrimitives->getSize())
    delete currentPrimitives->removeLast();
  delete objects;
  delete currentPrimitives;
}

void SVGOEController::updateMousePosition(double x,double y) {
  mouseX = x;
  mouseY = y;
}

vec2 SVGOEController::getMousePosition() {
  return vec2((float)mouseX,(float)mouseY);
}

void SVGOEController::render() {
  // to be implemeneted
}

void SVGOEController::handleClick() {
  // to be implemented
}

void SVGOEController::handleClick(int key) {
  // to be implemented
}

void SVOGEController::switchToEditMode(EditMode mode) {
  editMode = mode;
}

int SVGOEController::getCurrentObj() { return currentObj; }
int SVGOEController::getCurrentPrimitive() { return currentPrimitive; }

void SVGOEController::setCurrentObj(int param) { currentObj = param; }
void SVGOEController::setCurrentPrimitive(int param) { currentPrimitive = param; }
