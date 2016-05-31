#include "svgPrimitive.h"

SVGPrimitive::SVGPrimitive() {
  alignment = ALIGNMENT_CENTER;
  bb = rect();
  hasMoved = true;
}

vec2 SVGPrimitive::getPosition() {
  if(hasMoved) {
    calculateBB();
    hasMoved = false;
  }
  vec2 position = vec2(0);
  switch(alignment) {
    case ALIGNMENT_CENTER: {
      position = vec2(bb.pos.x+bb.dim.x/2.0f,bb.pos.y+bb.dim.y/2.0f);
      break;
    }
    case ALIGNMENT_TOP_RIGHT: {
      position = vec2(bb.pos.x+bb.dim.x,bb.pos.y+bb.dim.y);
      break;
    }
    case ALIGNMENT_TOP_LEFT: {
      position = vec2(bb.pos.x,bb.pos.y+bb.dim.y);
      break;
    }
    case ALIGNMENT_BOT_RIGHT: {
      position = vec2(bb.pos.x+bb.dim.x,bb.pos.y);
      break;
    }
    case ALIGNMENT_BOT_LEFT: {
      position = vec2(bb.pos.x,bb.pos.y);
      break;
    }
    default: break;
  }
  return position;
}

rect SVGPrimitive::getBB() { return bb; }

void SVGPrimitive::setAlignment(AlignmentType param) { alignment = param; }
