#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include <iostream>
#include <SDL/SDL.h>
using namespace std;

namespace Bengine{
    extern void fatalError(string errorString);
}
#endif // ERRORS_H
