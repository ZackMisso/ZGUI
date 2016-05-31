#pragma once

#include "shader.h"

class FragShader : public Shader {
private:
public:
  FragShader(int len,const char* s);
  FragShader();
  ~FragShader();
};
