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
  switch(editMode) {
    case CHANGING_OBJECTS: {
      // to be implemented
      break;
    }
    case CHANGING_PRIMITIVES: {
      // to be implemented
      break;
    }
    case EDITING_CURVE: {
      // to be implemented
      break;
    }
    case EDITING_LINE: {
      // to be implemented
      break;
    }
    case CREATING: {
      // to be implemented
      break;
    }
    case EMPTY: {
      // to be implemented
      break;
    }
    default: break;
  }
}

void SVGOEController::handleClick() {
  switch(editMode) {
    case CHANGING_OBJECTS: {
      // to be implemented
      break;
    }
    case CHANGING_PRIMITIVES: {
      // to be implemented
      break;
    }
    case EDITING_CURVE: {
      // to be implemented
      break;
    }
    case EDITING_LINE: {
      // to be implemented
      break;
    }
    case CREATING: {
      // to be implemented
      break;
    }
    case EMPTY: {
      // to be implemented
      break;
    }
    default: break;
  }
}

void SVGOEController::handleKey(int key) {
  switch(editMode) {
    case CHANGING_OBJECTS: {
      // to be implemented
      break;
    }
    case CHANGING_PRIMITIVES: {
      // to be implemented
      break;
    }
    case EDITING_CURVE: {
      // to be implemented
      break;
    }
    case EDITING_LINE: {
      // to be implemented
      break;
    }
    case CREATING: {
      // to be implemented
      break;
    }
    case EMPTY: {
      // to be implemented
      break;
    }
    default: break;
  }
}

void SVGOEController::switchToEditMode(EditMode mode) {
  editMode = mode;
}

int SVGOEController::getCurrentObj() { return currentObj; }
int SVGOEController::getCurrentPrimitive() { return currentPrimitive; }

void SVGOEController::setCurrentObj(int param) { currentObj = param; }
void SVGOEController::setCurrentPrimitive(int param) { currentPrimitive = param; }
