#include "arbbeziercurve.h"
#include "../globalInclude.h"
#include "combinationcache.h"
#include <tgmath.h>

ArbBezierCurve::ArbBezierCurve() : BezierCurve() { }

ArbBezierCurve::ArbBezierCurve(Array<vec2>* pts) : BezierCurve(pts) { }

void ArbBezierCurve::evaluateCurve() {
  int numCtlPts = controlPoints->getSize();
  curve->clear();
  if(numCtlPts <= 2) {
    // do linear curve case
    for(int i=0;i<numCtlPts;i++)
      curve->add(controlPoints->get(i));
    return;
  }
  else {
    // NEED TO ADD LOGIC FOR WRAP AROUND
    int numEvalPoints = numCtlPts * EVAL_POINTS_PER_CTRL;
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
        ypos += tmp * controlPoints->get(j).y;
        xpos += tmp * controlPoints->get(j).x;
      }
      curve->add(vec2(xpos,ypos));
    }
  }
}

