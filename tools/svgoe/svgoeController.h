#pragma once

#include "../../svg/svgo.h"
#include "../../dataStructures/array.h"

class SVGOEController {
private:
  Array<SVGObject*>* objects;
  int currentObj;
public:
  SVGOEController();
  ~SVGOEController();
  // getter methods
  int getCurrentObj();
  // setter methods
  void setCurrentObj(int param);
};
