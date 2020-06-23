#include "Ghost.h"
#include "PacMan.h"

using namespace net::draconia::games::pacman::model;

Ghost::Ghost(const int iX, const int iY, const Direction eDirection, const QString &sName, const Color eColor)
    :   Liveable()
    ,   MoveablePiece(iX, iY, eDirection, 0)
    ,   mbVulnerable(false)
    ,   meColor(eColor)
    ,   msName(sName)
{ }

Ghost::Ghost(const Ghost &refCopy)
    :   Liveable(refCopy)
    ,   MoveablePiece(refCopy)
    ,   mbVulnerable(refCopy.isVulnerable())
    ,   meColor(refCopy.getColor())
    ,   msName(refCopy.getName())
{ }

Ghost::Ghost(Ghost &refToMove)
    :   Liveable(refToMove)
    ,   MoveablePiece(refToMove)
    ,   mbVulnerable(refToMove.isVulnerable())
    ,   meColor(refToMove.getColor())
    ,   msName(refToMove.getName())
{ }

void Ghost::collided(Piece &refCollider)
{
    if(QString(typeid(refCollider).name()) == "PacMan")
        {
        PacMan refPacMan = static_cast<PacMan &>(refCollider);

        if(refPacMan.isPoweredUp())
            die();
        else
            refPacMan.die();
        }
}

void Ghost::die()
{ }

Ghost::Color Ghost::getColor() const
{
    return(meColor);
}

QString &Ghost::getName() const
{
    return(const_cast<Ghost &>(*this).msName);
}

bool Ghost::isVulnerable() const
{
    return(mbVulnerable);
}

void Ghost::revive()
{ }

void Ghost::setColor(const Color eColor)
{
    meColor = eColor;

    setChanged();
    notifyObservers("Color");
}

void Ghost::setName(const QString &sName)
{
    msName = sName;

    setChanged();
    notifyObservers("Name");
}

void Ghost::setVulnerable(const bool bVulnerable)
{
    mbVulnerable = bVulnerable;

    setChanged();
    notifyObservers("Vulnerable");
}
