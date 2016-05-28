// This is the main class for the Scalable Vector Graphic Object Editor Tool

#define  GLFW_INCLUDE_GL3
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <iostream>

using namespace std;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);
void error(int error, const char* description);

int main() {
  cout << "SVG Object Editor Tool" << endl;
}
