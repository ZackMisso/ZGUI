#pragma once

#include "../dataStructures/array.h"
#include "svgPrimitive.h"

class SVGObject {
protected:
  Array<SVGPrimitive*>* primitives;
public:
  SVGObject();
  ~SVGObject();
  virtual void render();
};
