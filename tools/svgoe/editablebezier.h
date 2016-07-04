#pragma once

#include "editableObject.h"
#include "../../datastructures/array.h"
#include "../../svg/arbbeziercurve.h"
#include "../../svg/quadbeziercurve.h"
#include "../../svg/cubicbeziercurve.h"
#include <glm/vec2.hpp>

using namespace glm;

enum EditableBezierMode {
  EDITBEZ_ARBITRARY,
  EDITBEZ_QUADRATIC,
  EDITBEZ_CUBIC
};

class EditableBezier : public EditableObject {
  Array<vec2>* controlPoints;
  Array<vec2>* curve;
  EditableBezierMode mode;
  bool wrapAround;
  bool dirty;
public:
  EditableBezier();
  ~EditableBezier();
  Array<vec2>* getCurve();
  void calculateArbitraryCurve();
  void calculateQuadraticCurve();
  void calculateCubicCurve();
  QuadBezierCurve* getQuadraticCurve();
  CubicBezierCurve* getCubicCurve();
  ArbBezierCurve* getArbitraryCurve();
  // Editable Object Methods
   
}
