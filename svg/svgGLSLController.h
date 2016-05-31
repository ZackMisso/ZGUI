#pragma once

// Is Responsible for reading and loading all of the shaders required for the
// gui.

class SVGGLSLController {
private:
public:
  SVGGLSLController();
  ~SVGGLSLController();
  void readAllShaders();
  void createAllPrograms();
  void compileAllPrograms();
  void cleanAllShaders();
  void cleanAllPrograms();
};
