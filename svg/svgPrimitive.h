#pragma once

// svg primitives are lines and curves. Currently the only curves are bezier curves

#include <glm/vec2.hpp>
#include "../dataStructures/rect.h"
#include "../shaderClasses/fragShader.h"
#include "../shaderClasses/vertShader.h"

using namespace glm;

enum AlignmentType {
  ALIGNMENT_CENTER,
  ALIGNMENT_TOP_RIGHT,
  ALIGNMENT_TOP_LEFT,
  ALIGNMENT_BOT_RIGHT,
  ALIGNMENT_BOT_LEFT
};

class SVGPrimitive {
protected:
  AlignmentType alignment;
  rect bb;
  VertShader* vert;
  FragShader* frag;
  GLuint vertShader;
  GLuint fragShader;
  GLuint vao;
  GLuint program;
  bool hasMoved;
  bool renderDirty;
public:
  SVGPrimitive();
  virtual void render() = 0;
  virtual void calculateBB() = 0;
  virtual void initializeBasic() = 0;
  virtual void setUpRendering() = 0;
  vec2 getPosition();
  // getter methods
  rect getBB();
  VertShader* getVert();
  FragShader* getFrag();
  GLuint getVertShader();
  GLuint getFragShader();
  GLuint getVao();
  GLuint getProgram();
  // setter methods
  void setAlignment(AlignmentType param);
  void setVert(VertShader* param);
  void setFrag(FragShader* param);
  void setVertShader(GLuint param);
  void setFragShader(GLuint param);
  void setVao(GLuint param);
  void setProgram(GLuint param);
};
