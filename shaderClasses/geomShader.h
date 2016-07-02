#pragma once

#include "shader.h"

class GeomShader : public Shader {
public:
  GeomShader(int len,const char* s);
  GeomShader();
  ~GeomShader();
};
