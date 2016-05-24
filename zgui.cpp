#include "zgui.h"
#include "defaultCallbacks.h"
#include <iostream>

using namespace std;

ZGUI* ZGUI::instance = 0x0;

ZGUI::ZGUI(int maj,int min,float swap) {
  renderCallback = 0x0;
  keyCallback = 0x0;
  mouseMoveCallback = 0x0;
  mouseClickCallback = 0x0;
  errorCallback = 0x0;
  major = maj;
  minor = min;
  swapInterval = swap;
  continuous = true;
}

ZGUI::~ZGUI() { /* not sure if needed yet */ }

void ZGUI::initialize(int maj,int min,float swap) {
  if(!instance)
    instance = new ZGUI(maj,min,swap);
}

void ZGUI::initGLFW() {
  if(!glfwInit()) {
    cout << "Error: GLFW Failed to Initialize" << endl;
    return;
  }
  glfwSetErrorCallback(error);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  GLFWwindow* application = glfwCreateWindow(1000,1000,"ZGUI - Test",NULL,NULL);
  glfwMakeContextCurrent(application);
  glfwSetKeyCallback(application,keyboard);
  glfwGetFramebufferSize(application, &applicationWidth, &applicationHeight);
  glViewport(0,0,applicationWidth,applicationHeight);
  glfwSwapInterval(1);

	applicationLoop();

  glfwDestroyWindow(application);
  glfwTerminate();
}

void ZGUI::destroy() {
  if(instance)
    delete instance;
}

void ZGUI::applicationLoop() {
  while (!glfwWindowShouldClose(application))
  {
    // Main Loop
    render();
    glfwSwapBuffers(application);
    glfwPollEvents();
  }
}

void ZGUI::setRenderCallback(void* param) { renderCallback = param; }
void ZGUI::setKeyCallback(void* param) { keyCallback = param; }
void ZGUI::setMouseMoveCallback(void* param) { mouseMoveCallback = param; }
void ZGUI::setMouseClickCallback(void* param) { mouseClickCallback = param; }
void ZGUI::setErrorCallback(void* param) { errorCallback = param; }
void ZGUI::setMajor(int param) { major = param; }
void ZGUI::setMinor(int param) { minor = param; }
void ZGUI::setApplicationWidth(int param) { applicationWidth = param; }
void ZGUI::setApplicationHeight(int param) { applicationHeight = param; }
void ZGUI::setContinuous(bool param) { continuous = param; }
