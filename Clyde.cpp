#include "Clyde.h"

using namespace net::draconia::games::pacman::model;

Clyde::Clyde()
    :   Ghost(215, 260, NoDirection, "Clyde")
{ }

Clyde::Clyde(const Clyde &refCopy)
    :   Ghost(refCopy)
{ }

Clyde::Clyde(Clyde &refToMove)
    :   Ghost(refToMove)
{ }

void Clyde::executeAI()
{ }
