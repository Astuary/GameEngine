#ifndef WINDOW_H
#define WINDOW_H

#define GLEW_STATIC
#include<SDL/SDL.h>
#include<GL/glew.h>
#include<string>
#include<errors.h>

namespace Bengine{
    enum WindowFlags {INVISIBLE=0x1, FULLSCREEN=0x2, BORDERLESS=0x4};

    class Window
    {
        public:
            Window();
            ~Window();

            int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
            void swapBuffer();
            int getScreenWidth();
            int getScreenHeight();

        protected:

        private:
            SDL_Window* _sdlwindow;
            int _screenWidth;
            int _screenHeight;
    };
}

#endif // WINDOW_H
