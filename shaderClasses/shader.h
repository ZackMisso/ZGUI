#pragma once

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class Shader {
private:
  GLenum shaderType;
  GLint bytes;
  GLchar* source;
  GLuint shaderObj;
public:
  Shader(GLenum type,int len,const char* s);
  Shader(GLenum type);
  ~Shader();
  bool readFile(const char* file);
  void deleteShader();
  // static functions
  static GLuint compileShader(Shader* vert,Shader* frag);
  static void checkCompileLog(const GLuint shader);
  // getter methods
  GLuint getShaderObj() const;
  GLchar* getSource() const;
  GLint getBytes() const;
  // setter methods
  void setShaderObj(GLint param);
};
