#include "shaderProgram.h"

ShaderProgram::ShaderProgram() {
  vert = 0x0;
  frag = 0x0;
  tessE = 0x0;
  tessC = 0x0;
  geom = 0x0;
  comp = 0x0;
  program = 0;
  ownsShaders = false;
}

ShaderProgram::~ShaderProgram() {
  if(ownsShaders) {
    if(vert) delete vert;
    if(frag) delete frag;
    if(tessE) delete tessE;
    if(tessC) delete tessC;
    if(geom) delete geom;
    if(comp) delete comp;
  } else {
    vert = 0x0;
    frag = 0x0;
    tessE = 0x0;
    tessC = 0x0;
    geom = 0x0;
    comp = 0x0;
  }
  // delete program
  glDeleteProgram(program);
}

void ShaderProgram::compileAndLink() {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint tessCShader;
  GLuint tessEShader;
  GLuint geomShader;
  GLuint compShader;
  // create and compile vert shader
  if(vert) {
    if(vert->getCompiled()) vertShader = vert->getShaderObj();
    else {
      vertShader = glCreateShader(GL_VERTEX_SHADER);
      const GLchar* vertSource = vert->getSource();
      const GLint vertLength = vert->getBytes();
      glShaderSource(vertShader,1,&vertSource,&vertLength);
      glCompileShader(vertShader);
      checkCompileLog(vertShader);
      vert->setCompiled(true);
    }
  }
  // create and compile frag shader
  if(frag) {
    if(frag->getCompiled()) fragShader = frag->getShaderObj();
    else {
      fragShader = glCreateShader(GL_FRAGMENT_SHADER);
      const GLchar* fragSource = frag->getSource();
      const GLint fragLength = frag->getBytes();
      glShaderSource(fragShader,1,&fragSource,&fragLength);
      glCompileShader(fragShader);
      checkCompileLog(fragShader);
      frag->setCompiled(true);
    }
  }
  // create and compile tessC shader
  if(tessC) {
    if(tessC->getCompiled()) tessCShader = tessC->getShaderObj();
    else {
      tessCShader = glCreateShader(GL_TESS_CONTROL_SHADER);
      const GLchar* tessCSource = tessC->getSource();
      const GLint tessCLength = tessC->getBytes();
      glShaderSource(tessCShader,1,&tessCSource,&tessCLength);
      glCompileShader(tessCShader);
      checkCompileLog(tessCShader);
      tessC->setCompiled(true);
    }
  }
  // create and compile tessE shader
  if(tessE) {
    if(tessE->getCompiled()) tessEShader = tessE->getShaderObj();
    else {
      tessEShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
      const GLchar* tessESource = tessE->getSource();
      const GLint tessELength = tessE->getBytes();
      glShaderSource(tessEShader,1,&tessESource,&tessELength);
      glCompileShader(tessEShader);
      checkCompileLog(tessEShader);
      tessE->setCompiled(true);
    }
  }
  // create and compile geom shader
  if(geom) {
    if(geom->getCompiled()) geomShader = geom->getShaderObj();
    else {
      geomShader = glCreateShader(GL_GEOMETRY_SHADER);
      const GLchar* geomSource = geom->getSource();
      const GLint geomLength = geom->getBytes();
      glShaderSource(geomShader,1,&geomSource,&geomLength);
      glCompileShader(geomShader);
      checkCompileLog(geomShader);
      geom->setCompiled(true);
    }
  }
  // create and compile comp shader
  if(comp) {
    if(comp->getCompiled()) compShader = comp->getShaderObj();
    else {
      compShader = glCreateShader(GL_GEOMETRY_SHADER);
      const GLchar* compSource = comp->getSource();
      const GLint compLength = comp->getBytes();
      glShaderSource(compShader,1,&compSource,&compLength);
      glCompileShader(compShader);
      checkCompileLog(compShader);
      comp->setCompiled(true);
    }
  }
  // create program, attach it, and link
  program = glCreateProgram();
  if(vert) glAttachShader(program,vertShader);
  if(tessC) glAttachShader(program,tessCShader);
  if(tessE) glAttachShader(program,tessEShader);
  if(frag) glAttachShader(program,fragShader);
  if(geom) glAttachShader(program,geomShader);
  if(comp) glAttachShader(program,compShader);
  glLinkProgram(program);
  // update the shaders
  if(vert) vert->setShaderObj(vertShader);
  if(frag) frag->setShaderObj(fragShader);
  if(tessC) tessC->setShaderObj(tessCShader);
  if(tessE) tessE->setShaderObj(tessEShader);
  if(geom) geom->setShaderObj(geomShader);
  if(comp) comp->setShaderObj(compShader);
  // now detach the shaders
  detachShaders();
}

void ShaderProgram::detachShaders() {
  if(vert) glDetachShader(program,vert->getShaderObj());
  if(frag) glDetachShader(program,frag->getShaderObj());
  if(tessC) glDetachShader(program,tessC->getShaderObj());
  if(tessE) glDetachShader(program,tessE->getShaderObj());
  if(geom) glDetachShader(program,geom->getShaderObj());
  if(comp) glDetachShader(program,comp->getShaderObj());
}

void ShaderProgram::deleteProgram() {
  glDeleteProgram(program);
}

void ShaderProgram::programOwnsShaders(bool param) {
  ownsShaders = param;
}

VertShader* ShaderProgram::getVert() { return vert; }
FragShader* ShaderProgram::getFrag() { return frag; }
TessEShader* ShaderProgram::getTessE() { return tessE; }
TessCShader* ShaderProgram::getTessC() { return tessC; }
GeomShader* ShaderProgram::getGeom() { return geom; }
ComputeShader* ShaderProgram::getComp() { return comp; }

void ShaderProgram::setVert(VertShader* param) { vert = param; }
void ShaderProgram::setFrag(FragShader* param) { frag = param; }
void ShaderProgram::setTessE(TessEShader* param) { tessE = param; }
void ShaderProgram::setTessC(TessCShader* param) { tessC = param; }
void ShaderProgram::setGeom(GeomShader* param) { geom = param; }
void ShaderProgram::setComp(ComputeShader* param) { comp = param; }
