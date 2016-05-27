#pragma once

#include "../dataStructures/array.h"
#include "../svg/svgPrimitive.h"

class SVGObject {
private:
  Array<SVGPrimitive*>* primitives;
public:
  SVGObject();
  ~SVGObject();
  // getter methods
  Array<SVGPrimitive*>* getPrimitives();
  // setter methods
  void setPrimitives(Array<SVGPrimitive*>* param);
}
