#include "Clyde.h"

using namespace net::draconia::games::pacman::model;

Clyde::Clyde(const int iX, const int iY)
    :   Ghost(215 + iX, 260 + iY, NoDirection, "Clyde")
{ }

Clyde::Clyde(const Clyde &refCopy)
    :   Ghost(refCopy)
{ }

Clyde::Clyde(Clyde &refToMove)
    :   Ghost(refToMove)
{ }

void Clyde::executeAI()
{ }
