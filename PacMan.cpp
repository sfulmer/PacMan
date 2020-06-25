#include "GameModel.h"
#include "PacMan.h"
#include "PacManApp.h"
#include "PacManController.h"

using net::draconia::games::pacman::PacManApp;
using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::model;

PacMan::PacMan(const int iX, const int iY, const Direction eDirection, const unsigned uiLives)
    :   Liveable(uiLives)
    ,   MoveablePiece(iX, iY, eDirection)
    ,   mbPoweredUp(false)
    ,   miSeconds(-1)
    ,   mPtrImage(nullptr)
{ }

PacMan::PacMan(const PacMan&refCopy)
    :   Liveable(refCopy)
    ,   MoveablePiece(refCopy)
    ,   mbPoweredUp(refCopy.isPoweredUp())
    ,   miSeconds(refCopy.getSeconds())
    ,   mPtrImage(refCopy.mPtrImage)
{ }

PacMan::PacMan(PacMan &refToMove)
    :   Liveable(refToMove)
    ,   MoveablePiece(refToMove)
    ,   mbPoweredUp(refToMove.isPoweredUp())
    ,   miSeconds(refToMove.getSeconds())
    ,   mPtrImage(refToMove.mPtrImage)
{
    if(refToMove.mPtrImage != nullptr)
        {
        delete refToMove.mPtrImage;
        refToMove.mPtrImage = nullptr;
        }
}

PacMan::~PacMan()
{
    if(mPtrImage != nullptr)
        {
        delete mPtrImage;
        mPtrImage = nullptr;
        }
}

void PacMan::collided(Piece &refCollider)
{
    //GameModel &refModel = getGameModel();

    if(QString(typeid(refCollider).name()) == "Ghost")
        {
        if(isPoweredUp())
            ; // Do something with the score
        else
            die();
        }
}

void PacMan::die()
{
    if(getLives() > 0)
        setLives(getLives() - 1);
    else
        {;}// Game over
}

PacManController &PacMan::getController()
{
    return(static_cast<PacManApp *>(qApp)->getController());
}

GameModel &PacMan::getGameModel()
{
    return(getController().getModel());
}

QImage PacMan::getImage()
{
    if(mPtrImage == nullptr)
        mPtrImage = new QImage(":/images/PacMan.png");

    return(*mPtrImage);
}

int PacMan::getSeconds() const
{
    return(miSeconds);
}

bool PacMan::isPoweredUp() const
{
    return(mbPoweredUp);
}

void PacMan::revive()
{ }

void PacMan::setPoweredUp(const bool bPoweredUp)
{
    mbPoweredUp = bPoweredUp;

    setChanged();
    notifyObservers("PoweredUp");
}

void PacMan::setSeconds(const int iSeconds)
{
    miSeconds = iSeconds;

    setChanged();
    notifyObservers("Seconds");
}
