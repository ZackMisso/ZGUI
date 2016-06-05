#include "tessEShader.h"

TessEShader::TessEShader(int len,const char* s)
      : Shader(GL_TESS_EVALUATION_SHADER,len,s)
{ }

TessEShader::TessEShader()
      : Shader(GL_TESS_EVALUATION_SHADER)
{ }

TessEShader::~TessEShader() { }
