#pragma once

#include "point2.h"

class Vertex2 {
private:
  Color color;
  Point2 point;
public:
  Vertex2() {
    color = Color();
    point = Point2();
  }

  Vertex2(Point2 p) {
    point = p;
    color = Color();
  }

  Vertex2(Point2 p,Color c) {
    point = p;
    color = c;
  }

  // getter methods
  Color getColor() { return color; }
  Point2 getPoint() { return point; }
  // setter methods
  void setColor(Color param) { color = param; }
  void setPoint2(Point2 param) { point = param; }
};
