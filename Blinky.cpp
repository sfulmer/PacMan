#include "Blinky.h"

using namespace net::draconia::games::pacman::model;

Blinky::Blinky(const int iX, const int iY)
    :   Ghost(245 + iX, 210 + iY, NoDirection, "Blinky")
{ }

Blinky::Blinky(const Blinky &refCopy)
    :   Ghost(refCopy)
{ }

Blinky::Blinky(Blinky &refToMove)
    :   Ghost(refToMove)
{ }

void Blinky::executeAI()
{ }
