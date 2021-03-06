#pragma once

#include "editData.h"
#include "../../svg/svgo.h"
#include "../../svg/svgPrimitive.h"
#include "../../dataStructures/array.h"
#include "selectionRect.h"
#include <glm/vec2.hpp>

enum EditMode {
  CHANGING_OBJECTS,
  CHANGING_PRIMITIVES,
  EDITING_CURVE,
  EDITING_LINE,
  EDITING_POLYGON,
  CREATING,
  EMPTY
};

class SVGOEController {
private:
  Array<SVGObject*>* objects;
  Array<SVGPrimitive*>* currentPrimitives;
  SelectionRect* selectionRect;
  int currentObj;
  int currentPrimitive;
  double mouseX;
  double mouseY;
  EditMode editMode;
  EditData* editorData;
  bool selecting;
  //void renderCurrentObject();
  void switchMode(int key);
  void switchToEmpty();
  void switchToChgObj();
  void switchToChgPri();
  void switchToEdC();
  void switchToEdL();
  void switchToCreate();
public:
  SVGOEController();
  ~SVGOEController();
  void updateMousePosition(double x,double y);
  void handleClick();
  void handleKey(int key);
  vec2 getMousePosition();
  void render();
  void switchToEditMode(EditMode mode);
  // getter methods
  int getCurrentObj();
  int getCurrentPrimitive();
  // setter methods
  void setCurrentObj(int param);
  void setCurrentPrimitive(int param);
};
