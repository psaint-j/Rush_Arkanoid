#include "glfw/usr/local/include/GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include "./include/Arkanoid.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
	(void)error;
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
	(void)scancode;
	(void)mods;
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "ARKANOID", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
	int i;

	i = 0; 
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        int state_right = glfwGetKey(window, GLFW_KEY_RIGHT);
        int state_left = glfwGetKey(window, GLFW_KEY_LEFT);
        glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		if (state_right == GLFW_PRESS)
		{
			glViewport(i, 0, width, height);
			i = i + 5;
		}
		if (state_left == GLFW_PRESS)
		{
			glViewport(i, 0, width, height);
			i = i - 5;
		}
		glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRUE);
        //glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        //glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        //glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
