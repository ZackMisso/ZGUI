#include "svgo.h"

SVGObject::SVGObject() {
  primitives = new Array<SVGPrimitive*>();
}

SVGObject::~SVGObject() {
  while(primitives->getSize())
    delete primitives->removeLast();
}

Array<SVGPrimitive*>* SVGObject::getPrimitives() { return primitives; }

void SVGObject::setPrimitives(Array<SVGPrimitive*>* param) { primitives = param; }
