#include "fragShader.h"

FragShader::FragShader(int len,const char* s)
      : Shader(GL_FRAGMENT_SHADER,len,s)
{ }

FragShader::FragShader()
      : Shader(GL_FRAGMENT_SHADER)
{ }

FragShader::~FragShader() { }
