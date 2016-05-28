#pragma once

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class ZGUI {
private:
  static ZGUI* instance;
  GLFWwindow* application;
  void (*ZGUIRenderCallback)(void);
  void (*ZGUIMouseMoveCallback)(int,int);
  void (*ZGUIKeyCallback)(GLFWwindow*,int,int,int,int);
  void (*ZGUIMouseClickCallback)(int,int,int,int);
  void (*ZGUIErrorCallback)(int,const char*);
  int major;
  int minor;
  int applicationHeight;
  int applicationWidth;
  float swapInterval;
  bool continuous;
  ZGUI(int maj,int min,float swap);
public:
  ~ZGUI();
  // singleton methods
  static ZGUI* getInstance();
  static void initialize(int maj,int min,float swap);
  static void destroy();
  // methods
  void initGLFW();
  void applicationLoop();
  // setter methods
  void setRenderCallback(void (*param)(void));
  void setMouseMoveCallback(void (*param)(int,int));
  void setKeyCallback(void (*param)(GLFWwindow*,int,int,int,int));
  void setMouseClickCallback(void (*param)(int,int,int,int));
  void setErrorCallback(void (*param)(int,const char*));
  void setMajor(int param);
  void setMinor(int param);
  void setApplicationHeight(int param);
  void setApplicationWidth(int param);
  void setContinuous(bool param);
};
