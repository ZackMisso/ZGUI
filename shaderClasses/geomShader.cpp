#include "geomShader.h"

GeomShader::GeomShader(int len,const char* s)
      : Shader(GL_TESS_EVALUATION_SHADER,len,s)
{ }

GeomShader::GeomShader()
      : Shader(GL_TESS_EVALUATION_SHADER)
{ }

GeomShader::~GeomShader() { }
