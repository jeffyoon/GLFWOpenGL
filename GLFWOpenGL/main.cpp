//
//  main.cpp
//  GLFW OpenGL
//
//  Created by Jeff Yoon on 2017. 10. 12..
//  Copyright © 2017년 qdis. All rights reserved.
//

#include <iostream>

#define SDL_IMPL

#if defined(SDL_IMPL)
#include "display.hpp"

int main()
{
    Display display(800, 600, "OpenGL");

    while (!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
        display.Update();
    }

    return 0;
}

#elif defined(GLFW_IMPL)

#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

#include "GameWindow.hpp"

GameWindow *gameWindow;

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }


    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

//    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }

    if (!GLEW_VERSION_2_0)
    {
        std::cout << "OpenGL 2.0 API is not available." << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "glfw version: " << glfwGetVersionString() << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    gameWindow = new GameWindow(window, true, screenWidth, screenHeight);

    while (gameWindow->getRunning())
    {
        glfwPollEvents();

        /*
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 1, 0);
        glEnd();

        glfwSwapBuffers(window);
         */

        gameWindow->render();
        gameWindow->update();

        gameWindow->setRunning(!glfwWindowShouldClose(window));
    }

    delete gameWindow;
    std::cout << "delete gameWindow." << std::endl;

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

#endif
