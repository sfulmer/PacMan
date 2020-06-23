#include "Fruit.h"

using namespace net::draconia::games::pacman::model;

Fruit::Fruit(const int iX, const int iY)
    :   Eatable()
    ,   Piece(iX, iY)
{ }

Fruit::Fruit(const Fruit &refCopy)
    :   Eatable(refCopy)
    ,   Piece(refCopy)
{ }

Fruit::Fruit(Fruit &refToMove)
    :   Eatable(refToMove)
    ,   Piece(refToMove)
{ }

void Fruit::collided(Piece &refCollider)
{
    Q_UNUSED(refCollider);
}
