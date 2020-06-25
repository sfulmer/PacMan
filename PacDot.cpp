#include "GameModel.h"
#include "PacManApp.h"
#include "PacManController.h"
#include "PacDot.h"
#include <QString>

using net::draconia::games::pacman::PacManApp;
using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::model;

PacDot::PacDot(const int iX, const int iY)
    :   Eatable()
    ,   Piece(iX, iY)
    ,   mPtrImage(nullptr)
{ }

PacDot::PacDot(const PacDot &refCopy)
    :   Eatable(refCopy)
    ,   Piece(refCopy)
    ,   mPtrImage(refCopy.mPtrImage)
{ }

PacDot::PacDot(PacDot &refToMove)
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

PacDot::~PacDot()
{
    if(mPtrImage != nullptr)
        {
        delete mPtrImage;
        mPtrImage = nullptr;
        }
}

void PacDot::collided(Piece &refCollider)
{
    if(QString(typeid(refCollider).name()) == "PacMan")
        {
        setEaten(true);
        }
}

PacManController &PacDot::getController()
{
    return(static_cast<PacManApp *>(qApp)->getController());
}

QImage PacDot::getImage()
{
    if(mPtrImage == nullptr)
        mPtrImage = new QImage(":/images/PacDot.png");

    return(*mPtrImage);
}

GameModel &PacDot::getModel()
{
    return(getController().getModel());
}
