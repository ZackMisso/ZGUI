#pragma once

#include "editData.h"
#include "../../svg/svgCureve.hpp"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

using namespace glm;

class CurveEditData : public EditData {
  friend class SVGOEController;
private:
  SVGCurve* curve;
  vec2 selectedPoint;
  int selectedPointIndex;
  vec3 color;
  bool tab;
  bool editingColor;
  bool addingPoints;
  bool fill;
public:
  CurveEditData();
  ~CurveEditData();
};
