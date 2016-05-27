#pragma once

class Color {
private:
  float[3] val;
public:
  Color() {
    val[0] = 0.0f;
    val[1] = 0.0f;
    val[2] = 0.0f;
  }

  Color(float r,float g,float b) {
    val[0] = r;
    val[1] = g;
    val[2] = b;
  }

  // getter methods
  float red() { return val[0]; }
  float green() { return val[1]; }
  float blue() { return val[2]; }
  // setter methods
  void setRed(float param) { val[0] = param; }
  void setGreen(float param) { val[1] = param; }
  void setBlue(float param) { val[2] = param; }
};
