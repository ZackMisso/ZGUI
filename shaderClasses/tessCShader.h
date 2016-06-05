#pragma once

#include "shader.h"

class TessCShader : public Shader {
public:
  TessCShader(int len,const char* s);
  TessCShader();
  ~TessCShader();
};
