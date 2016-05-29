// This is the main class for the Scalable Vector Graphic Object Editor Tool

#include <iostream>
#include "../../zgui.h"
#include "svgoeController.h"

using namespace std;

// editor variables
SVGOEController* controller;
ZGUI* gui;

// openGL methods
void display();
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(GLFWwindow* window,double x,double y);
void mouseClick(GLFWwindow* window,int button,int action,int mods);
void error(int error, const char* description);

int main() {
  cout << "SVG Object Editor Tool" << endl;
  controller = new SVGOEController();
  ZGUI::initialize(4,1,1);
	gui = ZGUI::getInstance();
	gui->setRenderCallback(display);
	gui->setKeyCallback(keyboard);
	gui->setMouseMoveCallback(mouseMove);
	gui->setMouseClickCallback(mouseClick);
	gui->setErrorCallback(error);
	gui->initGLFW();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  controller->render();
}

void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  controller->handleKey(key);
}

void mouseMove(GLFWwindow* window,double x,double y) {
  controller->updateMousePosition(x,y);
}

void mouseClick(GLFWwindow* window,int button,int action,int mods) {
  controller->handleClick();
}

void error(int error, const char* description) {
  // to be implemented
}
