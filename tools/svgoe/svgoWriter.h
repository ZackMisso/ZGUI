#pragma once

#include "svgo.h"
#include <string>

using namespace std;

class SVGOWriter {
public:
  static void writeSVGObject(string file,SVGObject* object);
};
