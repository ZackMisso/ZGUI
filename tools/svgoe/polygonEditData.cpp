#include "polygonEditData.h"

PolygonEditData::PolygonEditData() {
  polygon = 0x0;
  selectedPoint = vec2(0);
  selectedPointIndex = -1;
  addingPoints = true;
}

PolygonEditData::~PolygonEditData() {
  polygon = 0x0;
}
