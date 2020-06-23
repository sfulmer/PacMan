#include "PowerPellet.h"

using namespace net::draconia::games::pacman::model;

PowerPellet::PowerPellet(const int iX, const int iY)
    :   Eatable()
    ,   Piece(iX, iY, 1)
{ }

PowerPellet::PowerPellet(const PowerPellet &refCopy)
    :   Eatable(refCopy)
    ,   Piece(refCopy)
{ }

PowerPellet::PowerPellet(PowerPellet &refToMove)
    :   Eatable(refToMove)
    ,   Piece(refToMove)
{ }

void PowerPellet::collided(Piece &refCollider)
{
    if(QString(typeid(refCollider).name()) == "PacMan")
        setEaten(true);
}
