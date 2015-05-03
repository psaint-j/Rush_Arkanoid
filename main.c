/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 04:28:41 by nbelkaid          #+#    #+#             */
/*   Updated: 2015/05/02 04:28:41 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glfw/usr/local/include/GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include "./include/Arkanoid.h"

void error_callback(int error, const char* description)
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

void        draw_rect(float x, float y, float width, float height)
{

        glBegin(GL_QUADS);
        glColor3d(0.0, 0.8, 1.0);
        glVertex2f(-width/2 + x, -height/2 + y);
        glVertex2f(-width/2 + x, height/2 + y);
        glVertex2f(width/2 + x, height/2 + y);
        glVertex2f(width/2 + x, -height/2 + y);
        glEnd();
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1376, 1032, "A R K A N O I D", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1, 1, 1, -1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        float	rel;
        int 	x;
        int 	y;

        rel	= ratio / 50;
        x = 1;
        y = 1;
        while (x < 14)
        {

             while (y++ < 14)
            {
            	//usleep(1000);
                draw_rect(-0.9f - 0.51f + ratio * x / (float)5, -0.9f + 1.0f + y/(float)15, 1 / ratio * (23/(float)100), 1/ratio * (6/(float)100));
                
            }
            y = 1;
            x++;
        }
        double i;
        double j;
        
        glfwGetCursorPos(window, &i , &j);
        if (i >= 0 && i <= 1376)
        i = (i /(width/2)) - 1;
        j = (j /(height/2)) - 1;
        printf("%lf\n", i);
        glColor3d(0.0, 0.8, 1.0);
        glBegin(GL_POLYGON);
        glVertex2d(i - 0.2, - 0.9);
        glVertex2d( i + 0.2,- 0.9);
        glVertex2d( i + 0.2,- 0.85);
        glVertex2d(i - 0.2, - 0.85);
        glEnd();
        //glFlush();
       

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

