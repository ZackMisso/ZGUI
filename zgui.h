#pragma once

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <glm/vec3.hpp>
#include "elements/guiObject.h"
#include "elements/guiContainer.h"

using namespace glm;

class ZGUI {
private:
  static ZGUI* instance;
  Array<GUIObject*>* objects;
  Array<GUIContainer*>* containers;
  GUIObject* selectedObject;
  GUIContainer* selectedContainer;
  GLFWwindow* application;
  void (*ZGUIRenderCallback)(void);
  void (*ZGUIMouseMoveCallback)(int,int);
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
  void display();
  void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
  void mouseMove(int x,int y);
  void mouseClick(int button,int state,int x,int y);
  void error(int error, const char* description);
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
  void setMouseMoveCallback(void (*param)(int,int));
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
