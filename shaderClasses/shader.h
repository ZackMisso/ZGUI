#ifndef __SHADER_H__
#define __SHADER_H__

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class Shader {
private:
  GLenum shaderType;
  GLint bytes;
  GLchar* source;
  GLuint shaderObj;
  bool compiled;
public:
  Shader(GLenum type,int len,const char* s);
  Shader(GLenum type);
  ~Shader();
  bool readFile(const char* file);
  void deleteShader();
  // static functions
  static GLuint compileShader(Shader* vert,Shader* frag);
  static GLuint compileShader(Shader* vert,Shader* frag,Shader* tessC,Shader* tessE);
  static GLuint compileShader(Shader* vert,Shader* frag,Shader* tessC,Shader* tessE,Shader* geom);
  static GLuint compileShader(Shader* vert,Shader* frag,Shader* tessC,Shader* tessE,Shader* geom,Shader* comp);
  static void checkCompileLog(const GLuint shader);
  // getter methods
  GLuint getShaderObj() const;
  GLchar* getSource() const;
  GLint getBytes() const;
  bool getCompiled() const;
  // setter methods
  void setShaderObj(GLint param);
  void setCompiled(bool param);
};

#endif
