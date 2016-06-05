#include "tessCShader.h"

TessCShader::TessCShader(int len,const char* s)
      : Shader(GL_TESS_CONTROL_SHADER,len,s)
{ }

TessCShader::TessCShader()
      : Shader(GL_TESS_CONTROL_SHADER)
{ }

TessCShader::~TessCShader() { }
