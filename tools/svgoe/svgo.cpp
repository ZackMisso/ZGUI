#include "svgo.h"

SVGObject::SVGObject() {
  primitives = new Array<SVGPrimitive*>();
}

SVGObject::~SVGObject() {
  while(primitives->getSize())
    delete primitives->removeLast();
}

Array<SVGPrimitive*>* SVGPrimitive::getPrimitives() { return primitives; }

void SVGPrimitive::setPrimitives(Array<SVGPrimitive*>* param) { primitives = param; }
