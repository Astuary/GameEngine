#include "Window.h"
//#include<SDL/SDL.h>
//#include<GL/glew.h>

using namespace Bengine;
Window::Window(): _sdlwindow(nullptr)
{
    //ctor
}

Window::~Window()
{
    //dtor
}

int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags){

    Uint32 flags = SDL_WINDOW_OPENGL;
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    if(currentFlags & INVISIBLE){
        flags |= SDL_WINDOW_HIDDEN;
    }
    if(currentFlags & FULLSCREEN){
        flags|= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if(currentFlags & BORDERLESS){
        flags |= SDL_WINDOW_BORDERLESS;
    }

    _sdlwindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

    if(_sdlwindow == nullptr){
        fatalError("SDL Window could not be created");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_sdlwindow);

    if(glContext == nullptr){
        fatalError("SDL_GL Context could not be created");
    }

    GLenum error = glewInit();
    if(error != GLEW_OK){
        fatalError("Could not initialize glew!");
    }

    std::cout<<"OpenGL ver: "<<glGetString(GL_VERSION)<<std::endl;

    glClearColor(150 ,50 ,0 ,1 );

    //set VSYNC
    SDL_GL_SetSwapInterval(1);

    //Enable alpha blend
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return 0;
}

void Window::swapBuffer(){
    SDL_GL_SwapWindow(_sdlwindow);
}

int Window::getScreenWidth(){return _screenWidth;}

int Window::getScreenHeight(){return _screenHeight;}
