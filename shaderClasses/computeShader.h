#pragma once

#include "shader.h"

class ComputeShader : public Shader {
public:
  ComputeShader(int len,const char* s);
  ComputeShader();
  ~ComputeShader();
};
