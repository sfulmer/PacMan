#include "Blinky.h"

using namespace net::draconia::games::pacman::model;

Blinky::Blinky()
    :   Ghost(215, 260, NoDirection, "Blinky")
{ }

Blinky::Blinky(const Blinky &refCopy)
    :   Ghost(refCopy)
{ }

Blinky::Blinky(Blinky &refToMove)
    :   Ghost(refToMove)
{ }

void Blinky::executeAI()
{ }