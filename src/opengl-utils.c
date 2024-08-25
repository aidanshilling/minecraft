#include "./opengl-utils.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdbool.h>

int initOpenGLCore(int majorVersion, int minorVersion) {
    if (glfwInit() == GL_FALSE) {
        fprintf(stderr, "Failed to initialize GLFW.");
        return -1;
    } 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

int initGLFWwindow(GLFWwindow** window, int width, int height, char* windowHint) {
    *window = glfwCreateWindow(width, height, windowHint, NULL, NULL);
    if (*window == NULL) {
        fprintf(stderr, "Failed to create GLFW window.\n");
        glfwTerminate();
        return -1;
    }
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window, int exitKey) {
    if (glfwGetKey(window, exitKey) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
