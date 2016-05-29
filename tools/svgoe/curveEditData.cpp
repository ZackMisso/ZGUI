#include "curveEditData.h"

CurveEditData::CurveEditData() {
  curve = 0x0;
  selectedPoint = vec2(0);
  selectedPointIndex = -1;
  color = vec3(0);
  tab = false;
  editingColor = false;
  tab = false;
  editingColor = false;
  addingPoints = false;
}

CurveEditData::~CurveEditData() {
  curve = 0x0;
}
