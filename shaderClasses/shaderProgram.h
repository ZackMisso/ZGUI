#pragma once

#include "vertShader.h"
#include "fragShader.h"
#include "tessEShader.h"
#include "tessCShader.h"
#include "geomShader.h"
#include "computeShader.h"

class ShaderProgram {
private:
  VertShader* vert;
  FragShader* frag;
  TessEShader* tessE;
  TessCShader* tessC;
  GeomShader* geom;
  ComputeShader* comp;
  GLuint program;
  bool ownsShaders;
public:
  ShaderProgram();
  ~ShaderProgram();
  void compileAndLink();
  void deleteShaders();
  void detachProgram();
  void programOwnsShaders(bool param);
  // getter methods
  VertShader* getVert();
  FragShader* getFrag();
  TessEShader* getTessE();
  TessCShader* getTessC();
  GeomShader* getGeom();
  ComputeShader* getComp();
  // setter methods
  void setVert(VertShader* param);
  void setFrag(FragShader* param);
  void setTessE(TessEShader* param);
  void setTessC(TessCShader* param);
  void setGeom(GeomShader* param);
  void setComp(ComputeShader* param);
};
