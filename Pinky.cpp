#include "Pinky.h"

using namespace net::draconia::games::pacman::model;

Pinky::Pinky(const int iX, const int iY)
    :   Ghost(285 + iX, 260 + iY, NoDirection, "Pinky")
{ }

Pinky::Pinky(const Pinky &refCopy)
    :   Ghost(refCopy)
{ }

Pinky::Pinky(Pinky &refToMove)
    :   Ghost(refToMove)
{ }

void Pinky::executeAI()
{ }
