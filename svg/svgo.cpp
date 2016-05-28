#include "svgo.h"

SVGObject::SVGObject() {
  primitives = new Array<SVGPrimitive*>();
}

SVGObject::~SVGObject() {
  while(primitives->getSize())
    delete primitives->removeLast();
}

void SVGObject::render() {
  // to be implemented
}
