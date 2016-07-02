#include "bezierCurve.h"
#include "../globalInclude.h"
#include "combinationcache.h"
#include <tgmath.h>

BezierCurve::BezierCurve() {
  controlPoints = new Array<vec2>();
  continuous = false;
  wrapAround = false;
  dirty = true;
}

BezierCurve::BezierCurve(Array<vec2>* pts) {
  controlPoints = pts;
  continuous = false;
  wrapAround = false;
  dirty = true;
}

Array<vec2>* BezierCurve::getCurve() {
  if(dirty) {
    evaluateCurve(*controlPoints,curve,wrapAround);
    dirty = false;
  }
  return curve;
}

void BezierCurve::evaluateCurve(const Array<vec2>& ctrlPts,Array<vec2>* evaluatedPoints,const bool& wrap) {
  int numCtlPts = ctrlPts.getSize();
  if(numCtlPts <= 2) {
    // do linear curve case
    for(int i=0;i<numCtlPts;i++)
      evaluatedPoints->add(ctrlPts.get(i));
    return;
  }
  else {
    // NEED TO ADD LOGIC FOR WRAP AROUND
    int numEvalPoints = numCtlPts * EVAL_POINTS_PER_CTRL;
    evaluatedPoints->clear();
    CombinationCache* cc = CombinationCache::getInstance();
    for(int i=0;i<numEvalPoints;i++) {
      float pos = ((float)i)/((float)numEvalPoints);
      float ompos = 1.0f - pos;
      float ypos = 0.0f;
      float xpos = 0.0f;
      float n = numCtlPts - 1;
      for(int j=0;j<numCtlPts;j++) {
        // TODO :: Make a HashMap for powf results
        float tmp = powf(pos,(float)j) * powf(ompos,(float)n-j);
        tmp *= cc->getCombination(n,j);
        ypos += tmp * ctrlPts.get(j).y;
        xpos += tmp * ctrlPts.get(j).x;
      }
      evaluatedPoints->add(vec2(xpos,ypos));
    }
  }
}

BezierCurve::~BezierCurve() {
  while(controlPoints->getSize())
    controlPoints->removeLast();
  delete controlPoints;
}

Array<vec2>* BezierCurve::getControlPoints() const { return controlPoints; }
bool BezierCurve::getContinuous() const { return continuous; }
bool BezierCurve::getWrapAround() const { return wrapAround; }

void BezierCurve::setControlPoints(Array<vec2>* param) { controlPoints = param; }
void BezierCurve::setContinuous(bool param) { continuous = param; }
void BezierCurve::setWrapAround(bool param) { wrapAround = param; }
