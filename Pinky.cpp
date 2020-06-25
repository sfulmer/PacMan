#include "Pinky.h"

using namespace net::draconia::games::pacman::model;

Pinky::Pinky()
    :   Ghost(290, 260, NoDirection, "Pinky")
{ }

Pinky::Pinky(const Pinky &refCopy)
    :   Ghost(refCopy)
{ }

Pinky::Pinky(Pinky &refToMove)
    :   Ghost(refToMove)
{ }

void Pinky::executeAI()
{ }
