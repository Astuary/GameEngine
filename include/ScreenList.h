#ifndef SCREENLIST_H
#define SCREENLIST_H

#include <vector>
#include <cstring>

#include "IMainGame.h"
#include "IGameScreen.h"

namespace Bengine{

    /*class IMainGame;
    class IGameScreen;*/

    class ScreenList
    {
        public:
            ScreenList(IMainGame* game);
            virtual ~ScreenList();

            IGameScreen* moveNext();
            IGameScreen* movePrevious();

            void setScreen(int nextScreen);
            void addScreen(IGameScreen* newScreen);

            void destroy();

            IGameScreen* getCurrent();

        protected:
            IMainGame* m_game = nullptr;
            std::vector<IGameScreen*> m_screen;
            int m_currentScreenIndex = -1;

        private:
    };
}
#endif // SCREENLIST_H
