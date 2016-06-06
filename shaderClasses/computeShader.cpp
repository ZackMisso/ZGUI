#include "computeShader.h"

ComputeShader::ComputeShader(int len,const char* s)
      : Shader(GL_TESS_EVALUATION_SHADER,len,s)
{ }

ComputeShader::ComputeShader()
      : Shader(GL_TESS_EVALUATION_SHADER)
{ }

ComputeShader::~ComputeShader() { }
