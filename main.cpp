// THIS MAIN CLASS ONLY DISPLAYS WHAT IS POSSIBLE WITH THIS LIBRARY

#include <iostream>
#include <glm/vec2.hpp>
#include "zgui.h"

using namespace glm;
using namespace std;

void display();
void reshape(int w,int h);
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(GLFWwindow* window,double x,double y);
void mouseClick(int button,int state,int x,int y);
void error(int error, const char* description);

int main() {
	vec2 vec = vec2(0.0f,1.5f);
	cout << "Vec y: " << vec.y << endl;
	cout << "Hello Lord, Firal" << endl;
	// initialize the GUI
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

void mouseMove(GLFWwindow* window,double x,double y) {
	// to be implemented
}

void mouseClick(int button,int state,int x,int y) {
	// to be implemented
}

void error(int error, const char* description) {
	// to be implemented
}
