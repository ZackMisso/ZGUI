#include "lineEditData.h"

LineEditData::LineEditData() {
  line = 0x0;
  selectedPoint = vec2(0);
  selectedColor = vec3(0);
  firstPointSelected = false;
  secondPointSelected = false;
}

LineEditData::~LineEditData() {
  line = 0x0;
}
