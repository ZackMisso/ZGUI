#pragma once

#include "../../svg/svgo.h"
#include <string>

using namespace std;

class SVGOReader {
public:
  static void readSVGObject(string file,SVGObject* object);
};
