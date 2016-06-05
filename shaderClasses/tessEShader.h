#pragma once

#include "shader.h"

class TessEShader : public Shader {
public:
  TessEShader(int len,const char* s);
  TessEShader();
  ~TessEShader();
};
