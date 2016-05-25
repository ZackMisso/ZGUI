#pragma once

class Point2 {
public:
  float x;
  float y;

  Point2() {
    x = 0.0f;
    y = 0.0f;
  }

  Point2(float one,float two) {
    x = one;
    y = two;
  }
};

class Point2i {
public:
  int x;
  int y;

  Point2() {
    x = 0;
    y = 0;
  }

  Point2(int one,int two) {
    x = one;
    y = two;
  }
};
