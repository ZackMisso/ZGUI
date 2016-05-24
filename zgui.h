#pragma once

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class ZGUI {
private:
  static ZGUI* instance;
  GLFWwindow* application;
  void* renderCallback;
  void* keyCallback;
  void* mouseMoveCallback;
  void* mouseClickCallback;
  void* errorCallback;
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
  ZGUI* getInstance();
  void initialize(int maj,int min,float swap);
  void destroy();
  // methods
  void initGLFW();
  void applicationLoop();
  // setter methods
  void setRenderCallback(void* param);
  void setKeyCallback(void* param);
  void setMouseMoveCallback(void* param);
  void setMouseClickCallback(void* param);
  void setErrorCallback(void* param);
  void setMajor(int param);
  void setMinor(int param);
  void setApplicationHeight(int param);
  void setApplicationWidth(int param);
  void setContinuous(bool param);
};
