#include "MoveablePiece.h"

using namespace net::draconia::games::pacman::model;

MoveablePiece::MoveablePiece(const int iX, const int iY, const Direction eDirection, const unsigned uiPoints)
    :   Piece(iX, iY, uiPoints)
    ,   meDirection(eDirection)
{ }

MoveablePiece::MoveablePiece(const MoveablePiece &refCopy)
    :   Piece(refCopy)
    ,   meDirection(refCopy.getDirection())
{ }

MoveablePiece::MoveablePiece(MoveablePiece &refToMove)
    :   Piece(refToMove)
    ,   meDirection(refToMove.getDirection())
{ }

MoveablePiece::Direction MoveablePiece::getDirection() const
{
    return(meDirection);
}

void MoveablePiece::setDirection(const Direction eDirection)
{
    meDirection = eDirection;

    setChanged();
    notifyObservers("Direction");
}
