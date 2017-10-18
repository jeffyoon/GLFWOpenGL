//
//  GameWindow.cpp
//  GLFW OpenGL
//
//  Created by Jeff Yoon on 2017. 10. 13..
//  Copyright © 2017년 qdis. All rights reserved.
//

#include "GameWindow.hpp"

typedef struct {
    GLfloat positionCoordinates[3];
} VertexData;

#define SQURE_SIZE  100

VertexData vertices[] = {
    {0.0f, 0.0f, 0.0f},
    {SQURE_SIZE, 0.0f, 0.0f},
    {SQURE_SIZE, SQURE_SIZE, 0.0f},
    {0.0f, SQURE_SIZE, 0.0f},
};

void GameWindow::setRunning(bool newRunning)
{
    _running = newRunning;
}

bool GameWindow::getRunning()
{
    return _running;
}

GameWindow::GameWindow(GLFWwindow* window, bool running, GLfloat width, GLfloat height):_window(window), _running(running), _width(width), _height(height), _vertexBufferID(0)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0, 0, _width, _height);
    
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, _width, 0, _height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid*)offsetof(VertexData, positionCoordinates));
}

void GameWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_QUADS, 0, 4);
    
    glfwSwapBuffers(_window);
}

void GameWindow::update()
{
    
}
