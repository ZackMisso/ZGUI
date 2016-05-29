#pragma once

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <glm/vec3.hpp>
#include "elements/guiObject.h"
#include "elements/guiContainer.h"

using namespace glm;

class ZGUI {
protected:
  static ZGUI* instance;
  Array<GUIObject*>* objects;
  Array<GUIContainer*>* containers;
  GUIObject* selectedObject;
  GUIContainer* selectedContainer;
  GLFWwindow* application;
  void (*ZGUIRenderCallback)(void);
  void (*ZGUIMouseMoveCallback)(GLFWwindow*,double,double);
  void (*ZGUIKeyCallback)(GLFWwindow*,int,int,int,int);
  void (*ZGUIMouseClickCallback)(int,int,int,int);
  void (*ZGUIErrorCallback)(int,const char*);
  vec3 clearColor;
  int major;
  int minor;
  int applicationHeight;
  int applicationWidth;
  float swapInterval;
  bool continuous;
  ZGUI(int maj,int min,float swap);
  // self callbacks
  static void display();
  static void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
  static void mouseMove(GLFWwindow* window,double x,double y);
  static void mouseClick(int button,int state,int x,int y);
  static void error(int error, const char* description);
public:
  ~ZGUI();
  // singleton methods
  static ZGUI* getInstance();
  static void initialize(int maj,int min,float swap);
  static void destroy();
  // methods
  void initGLFW();
  void applicationLoop();
  void addGUIObject(GUIObject* obj);
  void addGUIContainer(GUIContainer* cont);
  // setter methods
  void setRenderCallback(void (*param)(void));
  void setMouseMoveCallback(void (*param)(GLFWwindow*,double,double));
  void setKeyCallback(void (*param)(GLFWwindow*,int,int,int,int));
  void setMouseClickCallback(void (*param)(int,int,int,int));
  void setErrorCallback(void (*param)(int,const char*));
  void setClearColor(vec3 param);
  void setMajor(int param);
  void setMinor(int param);
  void setApplicationHeight(int param);
  void setApplicationWidth(int param);
  void setContinuous(bool param);
};
