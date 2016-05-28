#include "zgui.h"
#include "defaultCallbacks.h"
#include <iostream>

using namespace std;

ZGUI* ZGUI::instance = 0x0;

ZGUI::ZGUI(int maj,int min,float swap) {
  objects = new Array<GUIObject*>();
  containers = new Array<GUIContainer*>();
  selectedObject = 0x0;
  selectedContainer = 0x0;
  application = 0x0;
  ZGUIRenderCallback = 0x0;
  ZGUIKeyCallback = 0x0;
  ZGUIMouseMoveCallback = 0x0;
  ZGUIMouseClickCallback = 0x0;
  ZGUIErrorCallback = 0x0;
  clearColor = vec3(0);
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

void ZGUI::addGUIObject(GUIObject* obj) {
  objects->add(obj);
}

void ZGUI::addGUIContainer(GUIContainer* cont) {
  containers->add(cont);
}

void ZGUI::destroy() {
  if(instance)
    delete instance;
}

void ZGUI::applicationLoop() {
  while (!glfwWindowShouldClose(application))
  {
    // Main Loop
    ZGUIRenderCallback();
    display();
    glfwSwapBuffers(application);
    glfwPollEvents();
  }
}

void ZGUI::display() {
  for(int i=0;i<containers->getSize();i++)
    containers->get(i)->render();
  for(int i=0;i<objects->getSize();i++)
    objects->get(i)->render();
}

void ZGUI::keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  // to be implemented
}

void ZGUI::mouseMove(int x,int y) {
  // to be implemented
}

void ZGUI::mouseClick(int button,int state,int x,int y) {
  // to be implemented
}

void ZGUI::error(int error, const char* description) {
  // to be implemented
}

void ZGUI::setRenderCallback(void (*param)(void)) { ZGUIRenderCallback = param; }
void ZGUI::setMouseMoveCallback(void (*param)(int,int)) { ZGUIMouseMoveCallback = param; }
void ZGUI::setKeyCallback(void (*param)(GLFWwindow*,int,int,int,int)) { ZGUIKeyCallback = param; }
void ZGUI::setMouseClickCallback(void (*param)(int,int,int,int)) { ZGUIMouseClickCallback = param; }
void ZGUI::setErrorCallback(void (*param)(int,const char*)) { ZGUIErrorCallback = param; }
void ZGUI::setClearColor(vec3 param) { clearColor = param; }
void ZGUI::setMajor(int param) { major = param; }
void ZGUI::setMinor(int param) { minor = param; }
void ZGUI::setApplicationWidth(int param) { applicationWidth = param; }
void ZGUI::setApplicationHeight(int param) { applicationHeight = param; }
void ZGUI::setContinuous(bool param) { continuous = param; }
