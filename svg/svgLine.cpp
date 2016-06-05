#include "svgLine.h"
#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <iostream>

using namespace std;

SVGLine::SVGLine() {
  first = vec2();
  second = vec2();
  firstColor = vec3(1);
  secondColor = vec3(0);
  lineWidth = 1;
}

SVGLine::SVGLine(vec2 one,vec2 two) {
  first = one;
  second = two;
  firstColor = vec3(1);
  secondColor = vec3(1);
  lineWidth = 1;
}

void SVGLine::render() {
  // TODO :: Change to shaders
  //cout << "Rendering Line" << endl;
  //cout << "First: " << first.x << " " << first.y << endl;
  //cout << "Second: " << second.x << " " << second.y << endl;
  // THIS HAS BEEN DEPRECATED NOOOOOOO..... FUCK
  //glColor4f(0.0f,1.0f,0.0f,1.0f);
  //glBegin(GL_LINES);
  //glColor4f(firstColor.x,firstColor.y,firstColor.z,1.0f);
  //glVertex2f(first.x,first.y);
  //glColor4f(secondColor.x,secondColor.y,secondColor.z,1.0f);
  //glVertex2f(second.x,second.y);
  //glEnd();
}

void SVGLine::calculateBB() {
  float minX = 100.0f;
  float minY = 100.0f;
  float maxX = -100.0f;
  float maxY = -100.0f;
  if(first.x > second.x) {
    maxX = first.x;
    minX = second.x;
  } else {
    maxX = second.x;
    minX = first.x;
  }
  if(first.y > second.y) {
    maxX = first.y;
    minX = second.y;
  } else {
    maxX = second.y;
    minX = first.y;
  }
  bb = rect(minX,minY,maxX-minX,maxY-minY);
  hasMoved = false;
}

void SVGLine::initializeBasic() {
  cout << "Initializing Basic" << endl;
  first = vec2(-0.25,0);
  second = vec2(0.25,0);
  lineWidth = 1;
}

void SVGLine::setUpRendering() {
  // to be implemented
}

vec2 SVGLine::getFirst() { return first; }
vec2 SVGLine::getSecond() { return second; }
vec3 SVGLine::getFirstColor() { return firstColor; }
vec3 SVGLine::getSecondColor() { return secondColor; }
float SVGLine::getLineWidth() { return lineWidth; }

void SVGLine::setFirst(vec2 param) { first = param; }
void SVGLine::setSecond(vec2 param) { second = param; }
void SVGLine::setFirstColor(vec3 param) { firstColor = param; }
void SVGLine::setSecondColor(vec3 param) { secondColor = param; }
void SVGLine::setLineWidth(float param) { lineWidth = param; }
