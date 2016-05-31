#pragma once

#include "../../svg/svgo.h"
#include <string>

using namespace std;

class SVGOReader {
public:
  static void readSVGObject(string file,SVGObject* object);
  static void readSVGPrimitive();
  static void readSVGLine();
  static void readSVGCurve();
  static void readSVGPolygon();
};
