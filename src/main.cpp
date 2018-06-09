#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
	GLFWwindow* window;

	// Initializing GLFW
	if(!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Initializing GLEW
	if (GLEW_OK != glewInit())
		return -1;

	// OpenGL Version
	std::cout << glGetString(GL_VERSION) << std::endl;

	while(!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		// Draw triangle
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
