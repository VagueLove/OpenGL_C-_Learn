#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


void init(GLFWwindow* window) { }

void display(GLFWwindow* window, double currentTime)
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main()
{
	using namespace std;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Hello, world", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
		exit(EXIT_FAILURE);
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}