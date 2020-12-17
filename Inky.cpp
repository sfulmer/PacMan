#include "Inky.h"

using namespace net::draconia::games::pacman::model;

Inky::Inky(const int iX, const int iY)
    :   Ghost(250 + iX, 260 + iY, NoDirection, "Inky")
{ }

Inky::Inky(const Inky &refCopy)
    :   Ghost(refCopy)
{ }

Inky::Inky(Inky &refToMove)
    :   Ghost(refToMove)
{ }

void Inky::executeAI()
{ }
