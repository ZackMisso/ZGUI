// This is the main class for the Scalable Vector Graphic Object Editor Tool

#include <iostream>
#include "zgui.h"

using namespace std;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);
void error(int error, const char* description);

int main() {
  cout << "SVG Object Editor Tool" << endl;
  ZGUI::initialize(4,1,1);
	ZGUI* gui = ZGUI::getInstance();
	gui->setRenderCallback(display);
	gui->setKeyCallback(keyboard);
	gui->setMouseMoveCallback(mouseMove);
	gui->setMouseClickCallback(mouseClick);
	gui->setErrorCallback(error);
	gui->initGLFW();
}

void display() {
  cout << "Rendering Loop Called" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void reshape(int w,int h) {
  // to be implemented
}

void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  // to be implemented
}

void mouseMove(int x,int y) {
  // to be implemented
}

void mouseClick(int button,int state,int x,int y) {
  // to be implemented
}

void error(int error, const char* description) {
  // to be implemented
}
