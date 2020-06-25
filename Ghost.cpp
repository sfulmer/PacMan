#include "Ghost.h"
#include "PacMan.h"

using namespace net::draconia::games::pacman::model;

Ghost::Ghost(const int iX, const int iY, const Direction eDirection, const QString &sName, const Color eColor)
    :   Liveable()
    ,   MoveablePiece(iX, iY, eDirection, 0)
    ,   mbVulnerable(false)
    ,   meColor(eColor)
    ,   mPtrImage(nullptr)
    ,   msName(sName)
{ }

Ghost::Ghost(const QString &sName, const Color eColor)
    :   Ghost(-1, -1, NoDirection, sName, eColor)
{ }

Ghost::Ghost(const Ghost &refCopy)
    :   Liveable(refCopy)
    ,   MoveablePiece(refCopy)
    ,   mbVulnerable(refCopy.isVulnerable())
    ,   meColor(refCopy.getColor())
    ,   mPtrImage(refCopy.mPtrImage)
    ,   msName(refCopy.getName())
{ }

Ghost::Ghost(Ghost &refToMove)
    :   Liveable(refToMove)
    ,   MoveablePiece(refToMove)
    ,   mbVulnerable(refToMove.isVulnerable())
    ,   meColor(refToMove.getColor())
    ,   mPtrImage(refToMove.mPtrImage)
    ,   msName(refToMove.getName())
{
    if(refToMove.mPtrImage != nullptr)
        {
        delete refToMove.mPtrImage;
        refToMove.mPtrImage = nullptr;
        }
}

Ghost::~Ghost()
{
    if(mPtrImage != nullptr)
        {
        delete mPtrImage;
        mPtrImage = nullptr;
        }
}

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

QImage Ghost::getImage()
{
    if(mPtrImage == nullptr)
        mPtrImage = new QImage(":/images/ghosts/" + getName() + ".png");

    return(*mPtrImage);
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
