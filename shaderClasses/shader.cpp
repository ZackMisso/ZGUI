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

GLuint Shader::compileShader(Shader* vert,Shader* frag,Shader* tessC,Shader* tessE) {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint tessCShader;
  GLuint tessEShader;
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
  // create and compile tessC shader
  if(glGetError() != GL_NO_ERROR) cout << "ERROR BEFORE TESS C" << endl;
  cout << "Tess C" << endl;
  tessCShader = glCreateShader(GL_TESS_CONTROL_SHADER);
  const GLchar* tessCSource = tessC->getSource();
  const GLint tessCLength = tessC->getBytes();
  glShaderSource(tessCShader,1,&tessCSource,&tessCLength);
  glCompileShader(tessCShader);
  checkCompileLog(tessCShader);
  // create and compile tessE shader
  if(glGetError() != GL_NO_ERROR) cout << "ERROR BEFORE TESS E" << endl;
  cout << "Tess E" << endl;
  tessEShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
  const GLchar* tessESource = tessE->getSource();
  const GLint tessELength = tessE->getBytes();
  glShaderSource(tessEShader,1,&tessESource,&tessELength);
  glCompileShader(tessEShader);
  checkCompileLog(tessEShader);
  // create program, attach it, and link
  if(glGetError() != GL_NO_ERROR) cout << "ERROR BEFORE LINK" << endl;
  program = glCreateProgram();
  glAttachShader(program,vertShader);
  glAttachShader(program,tessCShader);
  glAttachShader(program,tessEShader);
  glAttachShader(program,fragShader);
  glLinkProgram(program);
  GLint IsLinked;
	glGetProgramiv(program, GL_LINK_STATUS, (GLint *)&IsLinked);
	if(IsLinked==false)
	{
    cout << "NOT LIKNKED" << endl;
    GLint maxLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
		if(maxLength>0)
		{
			char *pLinkInfoLog = new char[maxLength];
			glGetProgramInfoLog(program, maxLength, &maxLength, pLinkInfoLog);
			cout << pLinkInfoLog << endl;
			delete [] pLinkInfoLog;
		}
  }
  if(glGetError() != GL_NO_ERROR) cout << "ERROR AFTER LINK" << endl;
  // update the shaders
  vert->setShaderObj(vertShader);
  frag->setShaderObj(fragShader);
  tessC->setShaderObj(tessCShader);
  tessE->setShaderObj(tessEShader);
  return program;
}

GLuint Shader::compileShader(Shader* vert,Shader* frag,Shader* tessC,Shader* tessE,Shader* geom) {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint tessCShader;
  GLuint tessEShader;
  GLuint geomShader;
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
  // create and compile tessC shader
  tessCShader = glCreateShader(GL_TESS_CONTROL_SHADER);
  const GLchar* tessCSource = tessC->getSource();
  const GLint tessCLength = tessC->getBytes();
  glShaderSource(tessCShader,1,&tessCSource,&tessCLength);
  glCompileShader(tessCShader);
  checkCompileLog(tessCShader);
  // create and compile tessE shader
  tessEShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
  const GLchar* tessESource = tessE->getSource();
  const GLint tessELength = tessE->getBytes();
  glShaderSource(tessEShader,1,&tessESource,&tessELength);
  glCompileShader(tessEShader);
  checkCompileLog(tessEShader);
  // create and compile geom shader
  geomShader = glCreateShader(GL_GEOMETRY_SHADER);
  const GLchar* geomSource = geom->getSource();
  const GLint geomLength = geom->getBytes();
  glShaderSource(geomShader,1,&geomSource,&geomLength);
  glCompileShader(geomShader);
  checkCompileLog(geomShader);
  // create program, attach it, and link
  program = glCreateProgram();
  glAttachShader(program,vertShader);
  glAttachShader(program,fragShader);
  glAttachShader(program,tessCShader);
  glAttachShader(program,tessEShader);
  glAttachShader(program,geomShader);
  glLinkProgram(program);
  // update the shaders
  vert->setShaderObj(vertShader);
  frag->setShaderObj(fragShader);
  tessC->setShaderObj(tessCShader);
  tessE->setShaderObj(tessEShader);
  return program;
}

GLuint Shader::compileShader(Shader* vert,Shader* frag,Shader* tessC,Shader* tessE,Shader* geom,Shader* comp) {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint tessCShader;
  GLuint tessEShader;
  GLuint geomShader;
  GLuint compShader;
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
  // create and compile tessC shader
  tessCShader = glCreateShader(GL_TESS_CONTROL_SHADER);
  const GLchar* tessCSource = tessC->getSource();
  const GLint tessCLength = tessC->getBytes();
  glShaderSource(tessCShader,1,&tessCSource,&tessCLength);
  glCompileShader(tessCShader);
  checkCompileLog(tessCShader);
  // create and compile tessE shader
  tessEShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
  const GLchar* tessESource = tessE->getSource();
  const GLint tessELength = tessE->getBytes();
  glShaderSource(tessEShader,1,&tessESource,&tessELength);
  glCompileShader(tessEShader);
  checkCompileLog(tessEShader);
  // create and compile geom shader
  geomShader = glCreateShader(GL_GEOMETRY_SHADER);
  const GLchar* geomSource = geom->getSource();
  const GLint geomLength = geom->getBytes();
  glShaderSource(geomShader,1,&geomSource,&geomLength);
  glCompileShader(geomShader);
  checkCompileLog(geomShader);
  // create and compile comp shader
  compShader = glCreateShader(GL_GEOMETRY_SHADER);
  const GLchar* compSource = comp->getSource();
  const GLint compLength = comp->getBytes();
  glShaderSource(compShader,1,&compSource,&compLength);
  glCompileShader(compShader);
  checkCompileLog(compShader);
  // create program, attach it, and link
  program = glCreateProgram();
  glAttachShader(program,vertShader);
  glAttachShader(program,tessCShader);
  glAttachShader(program,tessEShader);
  glAttachShader(program,fragShader);
  glAttachShader(program,geomShader);
  glAttachShader(program,compShader);
  glLinkProgram(program);
  // update the shaders
  vert->setShaderObj(vertShader);
  frag->setShaderObj(fragShader);
  tessC->setShaderObj(tessCShader);
  tessE->setShaderObj(tessEShader);
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
