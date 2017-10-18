//
//  display.hpp
//  GLFW OpenGL
//
//  Created by Jeff Yoon on 2017. 10. 13..
//  Copyright © 2017년 qdis. All rights reserved.
//

#ifndef display_hpp
#define display_hpp

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Display
{
public:
    Display(int width, int height, const std::string& title);
    void Update();
    bool IsClosed();
    void Clear(float r, float g, float b, float a);
    virtual ~Display();

private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;
};

#endif /* display_hpp */
