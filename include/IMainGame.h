#ifndef IMainGame_H
#define IMainGame_H

#include <memory>

#include "Window.h"
#include "Bengine.h"
#include "InputManager.h"

namespace Bengine{

    class ScreenList;
    class IGameScreen;

    class IMainGame
    {
        public:
            IMainGame();
            virtual ~IMainGame();

            void run();
            void exitGame();

            virtual void onInit() = 0;
            virtual void addScreens() = 0;
            virtual void onExit() = 0;

            const float getFps() const{
                return m_fps;
            }

            void onSDLEvent(SDL_Event& evnt);

            InputManager inputManager;

        protected:

            virtual void update();
            virtual void draw();

            bool init();
            bool initSystems();

            std::unique_ptr<ScreenList> m_screenList = nullptr;
            IGameScreen* m_currentScreen = nullptr;
            bool m_isRunning = false;
            float m_fps = 0.0f;
            Window m_window;

        private:
    };

}
#endif // IMainGame_H
