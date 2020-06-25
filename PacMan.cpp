#include "GameModel.h"
#include "PacMan.h"
#include "PacManApp.h"
#include "PacManController.h"

using net::draconia::games::pacman::PacManApp;
using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::model;

QImage PacMan::getClosedMouthImage()
{
    if(mPtrClosed == nullptr)
        mPtrClosed = new QImage(":/images/PacMan/Closed.png");

    return(*mPtrClosed);
}

QImage PacMan::getOpenMouthImage()
{
    if(mPtrOpen == nullptr)
        mPtrOpen = new QImage(":/images/PacMan/Open.png");

    return(*mPtrOpen);
}

PacMan::PacMan(const int iX, const int iY, const Direction eDirection, const unsigned uiLives)
    :   Liveable(uiLives)
    ,   MoveablePiece(iX, iY, eDirection)
    ,   mbPoweredUp(false)
    ,   miSeconds(-1)
    ,   mPtrClosed(nullptr)
    ,   mPtrOpen(nullptr)
{ }

PacMan::PacMan(const PacMan&refCopy)
    :   Liveable(refCopy)
    ,   MoveablePiece(refCopy)
    ,   mbPoweredUp(refCopy.isPoweredUp())
    ,   miSeconds(refCopy.getSeconds())
    ,   mPtrClosed(refCopy.mPtrClosed)
    ,   mPtrOpen(refCopy.mPtrOpen)
{ }

PacMan::PacMan(PacMan &refToMove)
    :   Liveable(refToMove)
    ,   MoveablePiece(refToMove)
    ,   mbPoweredUp(refToMove.isPoweredUp())
    ,   miSeconds(refToMove.getSeconds())
    ,   mPtrClosed(refToMove.mPtrClosed)
    ,   mPtrOpen(refToMove.mPtrOpen)
{
    if(refToMove.mPtrClosed != nullptr)
        {
        delete refToMove.mPtrClosed;
        refToMove.mPtrClosed = nullptr;
        }

    if(refToMove.mPtrOpen != nullptr)
        {
        delete refToMove.mPtrOpen;
        refToMove.mPtrOpen = nullptr;
        }
}

PacMan::~PacMan()
{
    if(mPtrClosed != nullptr)
        {
        delete mPtrClosed;
        mPtrClosed = nullptr;
        }

    if(mPtrOpen != nullptr)
        {
        delete mPtrOpen;
        mPtrOpen = nullptr;
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
    return(getOpenMouthImage());
}

int PacMan::getSeconds() const
{
    return(miSeconds);
}

QSize PacMan::getSize() const
{
    return(QSize(18, 18));
}

bool PacMan::isPoweredUp() const
{
    return(mbPoweredUp);
}

void PacMan::render(qint64 frame, QPainter &refPainter)
{
    refPainter.save();

    if((frame % 2) == 0)
        refPainter.drawImage(QRectF(getTopLeft(), getSize()), getClosedMouthImage());
    else
        refPainter.drawImage(QRectF(getTopLeft(), getSize()), getOpenMouthImage());

    refPainter.restore();
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
