#pragma once

#include "editData.h"
#include "../../svg/svgPolygon.h"
#include <glm/vec2.hpp>

using namespace glm;

class PolygonEditData : public EditData {
  friend class SVGOEController;
private:
  SVGPolygon* polygon;
  vec2 selectedPoint;
  int selectedPointIndex;
  bool addingPoints;
  bool tab;
  bool editingColor;
  bool fill;
public:
  PolygonEditData();
  ~PolygonEditData();
};
