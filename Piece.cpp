#include "Piece.h"

using namespace net::draconia::games::pacman::model;

Piece::Piece(const int iX, const int iY, const unsigned uiPoints)
    :   Observable()
    ,   miX(iX)
    ,   miY(iY)
    ,   muiPoints(uiPoints)
{ }

Piece::Piece(const Piece &refCopy)
    :   Observable(refCopy)
    ,   miX(refCopy.getX())
    ,   miY(refCopy.getY())
    ,   muiPoints(refCopy.getPoints())
{ }

Piece::Piece(Piece &refToMove)
    :   Observable(refToMove)
    ,   miX(refToMove.getX())
    ,   miY(refToMove.getY())
    ,   muiPoints(refToMove.getPoints())
{ }

unsigned Piece::getPoints() const
{
    return(muiPoints);
}

QPoint Piece::getTopLeft() const
{
    return(QPoint(getX(), getY()));
}

int Piece::getX() const
{
    return(miX);
}

int Piece::getY() const
{
    return(miY);
}

void Piece::setPoints(const unsigned uiPoints)
{
    muiPoints = uiPoints;

    setChanged();
    notifyObservers("Points");
}

void Piece::setX(const int iX)
{
    miX = iX;

    setChanged();
    notifyObservers("X");
}

void Piece::setY(const int iY)
{
    miY = iY;

    setChanged();
    notifyObservers("Y");
}
