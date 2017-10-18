//
//  GameWindow.hpp
//  GLFW OpenGL
//
//  Created by Jeff Yoon on 2017. 10. 13..
//  Copyright © 2017년 qdis. All rights reserved.
//

#ifndef GameWindow_hpp
#define GameWindow_hpp

#include <iostream>
#include <GLFW/glfw3.h>

class GameWindow
{
private:
    bool _running;
    GLfloat _width;
    GLfloat _height;
    GLFWwindow* _window;
    GLuint _vertexBufferID;
    
public:
    void setRunning(bool newRunning);
    bool getRunning();
    
    GameWindow(GLFWwindow *window, bool running, GLfloat width, GLfloat height);
    
    void render();
    void update();
};

#endif /* GameWindow_hpp */
