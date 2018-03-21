#include "ScreenList.h"

using namespace Bengine;

ScreenList::ScreenList(IMainGame* game):
    m_game(game)
{
    //ctor
}

ScreenList::~ScreenList()
{
    destroy();
}

IGameScreen* ScreenList::moveNext(){
    IGameScreen* currentScreen = getCurrent();
    if(currentScreen->getNextScreenIndex() != SCREEN_INDEX_NO_SCREEN){
        m_currentScreenIndex = currentScreen->getNextScreenIndex();
    }
    return getCurrent();
}

IGameScreen* ScreenList::movePrevious(){
    IGameScreen* currentScreen = getCurrent();
    if(currentScreen->getPreviousScreenIndex() != SCREEN_INDEX_NO_SCREEN){
        m_currentScreenIndex = currentScreen->getPreviousScreenIndex();
    }
    return getCurrent();
}

void ScreenList::setScreen(int nextScreen){
    m_currentScreenIndex = nextScreen;
}

void ScreenList::addScreen(IGameScreen* newScreen){
    newScreen->m_screenIndex = m_screen.size();
    m_screen.push_back(newScreen);
    newScreen->build();
    newScreen->setParentGame(m_game);
}

void ScreenList::destroy(){
    for(size_t i = 0; i < m_screen.size(); i++){
        m_screen[i]->destroy();
    }
    m_screen.resize(0);
    m_currentScreenIndex = SCREEN_INDEX_NO_SCREEN;
}

IGameScreen* ScreenList::getCurrent(){
    if(m_currentScreenIndex == SCREEN_INDEX_NO_SCREEN) return nullptr;
    return m_screen[m_currentScreenIndex];
}
