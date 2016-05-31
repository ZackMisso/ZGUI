#include "vertShader.h"

VertShader::VertShader(int len,const char* s)
  :Shader(GL_VERTEX_SHADER,len,s)
{ }

VertShader::VertShader()
  :Shader(GL_VERTEX_SHADER)
{ }

VertShader::~VertShader() { }
