#pragma once

#include "editData.h"
#include "../../svg/svgLine.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

using namespace glm;

class LineEditData : public EditData {
  friend class SVGOEController;
private:
  SVGLine* line;
  vec2 selectedPoint;
  vec3 selectedColor;
  bool firstPointSelected;
  bool secondPointSelected;
  bool tab;
  bool editingColor;
public:
  LineEditData();
  ~LineEditData();
};
