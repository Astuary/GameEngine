#include "errors.h"

using namespace Bengine;
void Bengine::fatalError(string errorString){
    cout<<errorString<<endl;
    SDL_QUIT;
}
