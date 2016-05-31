#pragma once

#include "shader.h"

class VertShader : public Shader {
private:
public:
  VertShader(int len,const char* s);
  VertShader();
  ~VertShader();
};
