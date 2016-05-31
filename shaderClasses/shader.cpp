#include "shader.h"
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

Shader::Shader(GLenum type,int len,const char* s)
      :shaderType(type),bytes(len),shaderObj(0)
{
  source = new GLchar[bytes];
  if(source)
    for(int i=0;i<bytes;i++)
      source[i]=s[i];
}

Shader::Shader(GLenum type)
      :shaderType(type),source(NULL),shaderObj(0)
{ }

Shader::~Shader() {
  deleteShader();
  delete source;
}

bool Shader::readFile(const char* filename) {
  FILE *file = fopen(filename,"rb");
  if(file) {
    long size;
    fseek(file,0L,SEEK_END);
    size = ftell(file);
    fseek(file,0L,SEEK_SET);
    if(source)
      delete source;
    source = new GLchar[size];
    if(!source) {
      fprintf(stderr,"Error Reading Shader File\n");
      return false;
    }
    bytes = (int)fread(source,1,size,file);
    assert(bytes==size);
    fclose(file);
  } else {
    fprintf(stderr,"Could Not Open File\n");
    return false;
  }
  return true;
}

void Shader::deleteShader() {
  if(shaderObj) {
    glDeleteShader(shaderObj);
    shaderObj = 0;
  }
}

GLuint Shader::compileShader(Shader* vert,Shader* frag) {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint program;
  // create and compile vert shader
  vertShader = glCreateShader(GL_VERTEX_SHADER);
  const GLchar* vertSource = vert->getSource();
  const GLint vertLength = vert->getBytes();
  glShaderSource(vertShader,1,&vertSource,&vertLength);
  glCompileShader(vertShader);
  checkCompileLog(vertShader);
  // create and compile frag shader
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  const GLchar* fragSource = frag->getSource();
  const GLint fragLength = frag->getBytes();
  glShaderSource(fragShader,1,&fragSource,&fragLength);
  glCompileShader(fragShader);
  checkCompileLog(fragShader);
  // create program, attach it, and link
  program = glCreateProgram();
  glAttachShader(program,vertShader);
  glAttachShader(program,fragShader);
  glLinkProgram(program);
  // update the shaders
  vert->setShaderObj(vertShader);
  frag->setShaderObj(fragShader);
  return program;
}

void Shader::checkCompileLog(const GLuint shader) {
  GLint success = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if(success == GL_FALSE) {
    cout << "ERROR COMPILING SHADER" << endl;
    GLint logSize = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
	  vector<GLchar> errorLog(logSize);
	  glGetShaderInfoLog(shader, logSize, &logSize, &errorLog[0]);
    for(int i=0;i<errorLog.size()-1;i++) {
      cout << errorLog[i];
    }
    cout << endl;
  }
}

GLuint Shader::getShaderObj() const { return shaderObj; }
GLchar* Shader::getSource() const { return source; }
GLint Shader::getBytes() const { return bytes; }

void Shader::setShaderObj(int param) { shaderObj = param; }
