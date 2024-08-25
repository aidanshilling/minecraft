#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "opengl-utils.h"

int main() {
	
	if (initOpenGLCore(3, 3) == 0) {
		printf("Successfully initialized GLFW.\n");
	}

	GLFWwindow* window;
	if (initGLFWwindow(&window, 800, 600, "OpenGL test") == 0) {
		printf("Window created!\n");	
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		fprintf(stderr, "Failed to initialize GLAD.\n");
		return -1;
	}


	return 0;
}
