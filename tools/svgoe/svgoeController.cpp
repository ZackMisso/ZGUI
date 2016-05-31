#include "svgoeController.h"
#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "../../svg/svgLine.h"
#include "../../svg/svgCurve.h"
#include "../../svg/svgPolygon.h"
#include "../../svg/svgo.h"

SVGOEController::SVGOEController() {
  objects = new Array<SVGObject*>();
  currentPrimitives = new Array<SVGPrimitive*>();
  currentObj = 0;
  currentPrimitive = 0;
  mouseX = 0.0;
  mouseY = 0.0;
  editMode = EMPTY;
  editorData = 0x0;
  currentPrimitives->add(new SVGLine());
  currentPrimitives->get(0)->initializeBasic();
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
    case EDITING_POLYGON: {
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
  //currentObj->render();
  currentPrimitives->get(currentPrimitive)->render();
}

void SVGOEController::handleClick() {
  switch(editMode) {
    case CHANGING_OBJECTS: break;
    case CHANGING_PRIMITIVES: break;
    case EDITING_CURVE: {
      // to be implemented
      break;
    }
    case EDITING_LINE: {
      // to be implemented
      break;
    }
    case EDITING_POLYGON: {
      // to be implemented
      break;
    }
    case CREATING: break;
    case EMPTY: break;
    default: break;
  }
}

void SVGOEController::handleKey(int key) {
  if(key >= GLFW_KEY_0  && key <= GLFW_KEY_9) {
    switchMode(key);
  } else {
    switch(editMode) {
      case CHANGING_OBJECTS: {
        if(key == GLFW_KEY_UP) {
          currentObj = (currentObj==0) ? objects->getSize() : currentObj--;
        } else if(key == GLFW_KEY_DOWN) {
          currentObj = (currentObj==objects->getSize()) ? 0 : currentObj++;
        }
        break;
      }
      case CHANGING_PRIMITIVES: {
        if(key == GLFW_KEY_UP) {
          currentPrimitive = (currentPrimitive==0) ? currentPrimitives->getSize() : currentPrimitive--;
        } else if(key == GLFW_KEY_DOWN) {
          currentPrimitive = (currentPrimitive==currentPrimitives->getSize()) ? 0 : currentPrimitive++;
        }
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
      case EDITING_POLYGON: {
        // to be implemented
        break;
      }
      case CREATING: {
        if(key == GLFW_KEY_C) {
          // create a curve
          SVGCurve* curve = new SVGCurve();
          curve->initializeBasic();
          currentPrimitives->add(curve);
        } else if(key == GLFW_KEY_L) {
          // create a line
          SVGLine* line = new SVGLine();
          line->initializeBasic();
          currentPrimitives->add(line);
        } else if(key == GLFW_KEY_O) {
          // create an object
          SVGObject* object = new SVGObject();
          objects->add(object);
        } else if(key == GLFW_KEY_P) {
          // create a polygon
          SVGPolygon* polygon = new SVGPolygon();
          polygon->initializeBasic();
          currentPrimitives->add(polygon);
        } else if(key == GLFW_KEY_S) {
          // save and create object
        }
        break;
      }
      case EMPTY: break;
      default: break;
    }
  }
}

void SVGOEController::switchMode(int key) {
  switch(key) {
    case GLFW_KEY_0: editMode = EMPTY; switchToEmpty(); break;
    case GLFW_KEY_1: editMode = CHANGING_OBJECTS; switchToChgObj(); break;
    case GLFW_KEY_2: editMode = CHANGING_PRIMITIVES; switchToChgPri(); break;
    case GLFW_KEY_3: editMode = EDITING_CURVE; switchToEdC(); break;
    case GLFW_KEY_4: editMode = EDITING_LINE; switchToEdL(); break;
    case GLFW_KEY_5: editMode = CREATING; switchToCreate(); break;
    case GLFW_KEY_6: break;
    case GLFW_KEY_7: break;
    case GLFW_KEY_8: break;
    case GLFW_KEY_9: break;
    default: break;
  }
}

void SVGOEController::switchToEditMode(EditMode mode) {
  editMode = mode;
  switch(mode) {
    case CHANGING_OBJECTS: switchToChgObj(); break;
    case CHANGING_PRIMITIVES: switchToChgPri(); break;
    case EDITING_CURVE: switchToEdC(); break;
    case EDITING_LINE: switchToEdL(); break;
    case CREATING: switchToCreate(); break;
    case EMPTY: switchToEmpty(); break;
    default: break;
  }
}

void SVGOEController::switchToEmpty() {
  // does nothing
}

void SVGOEController::switchToChgObj() {
  // to be implemented
}

void SVGOEController::switchToChgPri() {
  // to be implemented
}

void SVGOEController::switchToEdC() {
  // to be implemented
}

void SVGOEController::switchToEdL() {
  // to be implemented
}

void SVGOEController::switchToCreate() {
  // to be implemented
}

int SVGOEController::getCurrentObj() { return currentObj; }
int SVGOEController::getCurrentPrimitive() { return currentPrimitive; }

void SVGOEController::setCurrentObj(int param) { currentObj = param; }
void SVGOEController::setCurrentPrimitive(int param) { currentPrimitive = param; }
