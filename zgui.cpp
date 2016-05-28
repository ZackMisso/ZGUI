#include "zgui.h"
#include "defaultCallbacks.h"
#include <iostream>

using namespace std;

ZGUI* ZGUI::instance = 0x0;

ZGUI::ZGUI(int maj,int min,float swap) {
  ZGUIRenderCallback = 0x0;
  ZGUIKeyCallback = 0x0;
  ZGUIMouseMoveCallback = 0x0;
  ZGUIMouseClickCallback = 0x0;
  ZGUIErrorCallback = 0x0;
  major = maj;
  minor = min;
  swapInterval = swap;
  continuous = true;
}

ZGUI::~ZGUI() { /* not sure if needed yet */ }

ZGUI* ZGUI::getInstance() {
  return instance;
}

void ZGUI::initialize(int maj,int min,float swap) {
  if(!instance)
    instance = new ZGUI(maj,min,swap);
}

void ZGUI::initGLFW() {
  if(!glfwInit()) {
    cout << "Error: GLFW Failed to Initialize" << endl;
    return;
  }
  //cout << "Setting Error Callback" << endl;
  glfwSetErrorCallback(ZGUIErrorCallback);
  //cout << "Setting Window Hints" << endl;
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  //cout << "Creating Window" << endl;
  application = glfwCreateWindow(1000,1000,"ZGUI - Test",NULL,NULL);
  glfwMakeContextCurrent(application);
  //cout << "Setting Key Callback" << endl;
  glfwSetKeyCallback(application,ZGUIKeyCallback);
  glfwGetFramebufferSize(application, &applicationWidth, &applicationHeight);
  glViewport(0,0,applicationWidth,applicationHeight);
  glfwSwapInterval(1);
  //cout << "Calling Application Loop" << endl;
	applicationLoop();
  //cout << "Destroying Application" << endl;
  glfwDestroyWindow(application);
  glfwTerminate();
}

void ZGUI::destroy() {
  if(instance)
    delete instance;
}

void ZGUI::applicationLoop() {
  //cout << "Calling Loop" << endl;
  while (!glfwWindowShouldClose(application))
  {
    // Main Loop
    //cout << "Before rendering" << endl;
    ZGUIRenderCallback();
    //cout << "After Rendering" << endl;
    glfwSwapBuffers(application);
    glfwPollEvents();
  }
}

void ZGUI::setRenderCallback(void (*param)(void)) { ZGUIRenderCallback = param; }
void ZGUI::setMouseMoveCallback(void (*param)(int,int)) { ZGUIMouseMoveCallback = param; }
void ZGUI::setKeyCallback(void (*param)(GLFWwindow*,int,int,int,int)) { ZGUIKeyCallback = param; }
void ZGUI::setMouseClickCallback(void (*param)(int,int,int,int)) { ZGUIMouseClickCallback = param; }
void ZGUI::setErrorCallback(void (*param)(int,const char*)) { ZGUIErrorCallback = param; }
void ZGUI::setMajor(int param) { major = param; }
void ZGUI::setMinor(int param) { minor = param; }
void ZGUI::setApplicationWidth(int param) { applicationWidth = param; }
void ZGUI::setApplicationHeight(int param) { applicationHeight = param; }
void ZGUI::setContinuous(bool param) { continuous = param; }
