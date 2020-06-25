#include "PowerPellet.h"

using namespace net::draconia::games::pacman::model;

PowerPellet::PowerPellet(const int iX, const int iY)
    :   Eatable()
    ,   Piece(iX, iY, 1)
    ,   mPtrImage(nullptr)
{ }

PowerPellet::PowerPellet(const PowerPellet &refCopy)
    :   Eatable(refCopy)
    ,   Piece(refCopy)
    ,   mPtrImage(refCopy.mPtrImage)
{ }

PowerPellet::PowerPellet(PowerPellet &refToMove)
    :   Eatable(refToMove)
    ,   Piece(refToMove)
    ,   mPtrImage(refToMove.mPtrImage)
{
    if(refToMove.mPtrImage != nullptr)
        {
        delete refToMove.mPtrImage;
        refToMove.mPtrImage = nullptr;
        }
}

PowerPellet::~PowerPellet()
{
    if(mPtrImage != nullptr)
        {
        delete mPtrImage;
        mPtrImage = nullptr;
        }
}

void PowerPellet::collided(Piece &refCollider)
{
    if(QString(typeid(refCollider).name()) == "PacMan")
        setEaten(true);
}

QImage PowerPellet::getImage()
{
    if(mPtrImage == nullptr)
        mPtrImage = new QImage(":/images/PowerPellet.png");

    return(*mPtrImage);
}
