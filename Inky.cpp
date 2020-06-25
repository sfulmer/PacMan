#include "Inky.h"

using namespace net::draconia::games::pacman::model;

Inky::Inky()
    :   Ghost(265, 260, NoDirection, "Inky")
{ }

Inky::Inky(const Inky &refCopy)
    :   Ghost(refCopy)
{ }

Inky::Inky(Inky &refToMove)
    :   Ghost(refToMove)
{ }

void Inky::executeAI()
{ }
