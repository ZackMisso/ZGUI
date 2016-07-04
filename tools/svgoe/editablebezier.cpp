#include "editablebezier.h"

EditableBezierCurve::EditableBezierCurve() {
  controlPoints = new Array<vec2>();
  curve = new Array<vec2>();
  mode = EDITBEZ_ARBITRARY;
  wrapAround = true;
  dirty = true;
}

EditableBezierCurve::~EditableBezierCurve() {
  while(controlPoints->getSize()) controlPoints->removeLast();
  while(curve->getSize()) curve->removeLast();
  delete controlPoints;
  delete curve;
}

Array<vec2>* EditableBezierCurve::getCurve() {
  if(dirty) {
    if(mode == EDITBEZ_ARBITRARY) calculateArbitraryCurve();
    if(mode == EDITBEZ_QUADRATIC) calculateQuadraticCurve();
    if(mode == EDITBEZ_CUBIC) calculateCubicCurve();
    dirty = false;
  }
  return curve;
}

void EditableBezierCurve::calculateArbitraryCurve() {
  // to be implemented
}

void EditableBezierCurve::calculateQuadraticCurve() {
  // to be implemented
}

void EditableBezierCurve::calculateCubicCurve() {
  // to be implemented
}

QuadBezierCurve* EditableBezierCurve::getQuadraticCurve() {
  if(mode != EDITBEZ_QUADRATIC) {
    calculateQuadraticCurve();
    dirty = false;
  }
  else {
    if(dirty) {
      calculateQuadraticCurve();
      dirty = false;
    }
  }
  QuadBezierCurve* newCurve = new QuadBezierCurve();
  BezierCurve::createCurveAndCopy(controlPts,curve,newCurve);
  return newCurve;
}

CubicBezierCurve* EditableBezierCurve::getCubicCurve() {
  if(mode != EDITBEZ_CUBIC) {
    calculateCubicCurve();
    dirty = false;
  }
  else {
    if(dirty) {
      calculateCubicBezierCurve();
      dirty = false;
    }
  }
  CubicBezierCurve newCurve = new CubicBezierCurve();
  BezierCurve::copyIntoCurve(controlPts,curve,newCurve);
  return newCurve;
}

ArbBezierCurve* EditableBezierCurve::getArbitraryCurve() {
  if(mode != EDITBEZ_ARBITRARY) {
    calculateArbitraryCurve();
    dirty = false;
  }
  else {
    if(dirty) {
      calculateArbitraryCurve();
      dirty = false;
    }
  }
  ArbBezierCurve* newCurve = new ArbBezierCurve();
  BezierCurve::createCurveAndCopy(controlPts,curve,newCurve);
  return newCurve;
}
