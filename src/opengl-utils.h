#include <GLFW/glfw3.h>

int initOpenGLCore(int majorVersion, int minorVersion);
int initGLFWwindow(GLFWwindow** window, int width, int height, char* windowHint);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, int exitKey);
