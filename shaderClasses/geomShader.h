#pragma once

#include "shader.h"

class TessEShader : public Shader {
public:
  GeomShader(int len,const char* s);
  GeomShader();
  ~GeomShader();
};
