#include "Ghost.h"
#include "PacMan.h"

using namespace net::draconia::games::pacman::model;

QImage Ghost::getNormalImage()
{
    if(mImgNormal == nullptr)
        mImgNormal = new QImage(":/images/ghosts/Normal/" + getName() + ".png");

    return(*mImgNormal);
}

QImage Ghost::getVulnerableImage()
{
    if(mImgVulnerable == nullptr)
        mImgVulnerable = new QImage(":/images/ghosts/Vulnerable/" + getName() + ".png");

    return(*mImgVulnerable);
}

Ghost::Ghost(const int iX, const int iY, const Direction eDirection, const QString &sName)
    :   Liveable()
    ,   MoveablePiece(iX, iY, eDirection, 0)
    ,   mbVulnerable(false)
    ,   mImgNormal(nullptr)
    ,   mImgVulnerable(nullptr)
    ,   msName(sName)
{ }

Ghost::Ghost(const QString &sName)
    :   Ghost(-1, -1, NoDirection, sName)
{ }

Ghost::Ghost(const Ghost &refCopy)
    :   Liveable(refCopy)
    ,   MoveablePiece(refCopy)
    ,   mbVulnerable(refCopy.isVulnerable())
    ,   mImgNormal(refCopy.mImgNormal)
    ,   mImgVulnerable(refCopy.mImgVulnerable)
    ,   msName(refCopy.getName())
{ }

Ghost::Ghost(Ghost &refToMove)
    :   Liveable(refToMove)
    ,   MoveablePiece(refToMove)
    ,   mbVulnerable(refToMove.isVulnerable())
    ,   mImgNormal(refToMove.mImgNormal)
    ,   mImgVulnerable(refToMove.mImgVulnerable)
    ,   msName(refToMove.getName())
{
    if(refToMove.mImgNormal != nullptr)
        {
        delete refToMove.mImgNormal;
        refToMove.mImgNormal = nullptr;
        }

    if(refToMove.mImgVulnerable != nullptr)
        {
        delete refToMove.mImgVulnerable;
        refToMove.mImgVulnerable = nullptr;
        }
}

Ghost::~Ghost()
{
    if(mImgNormal != nullptr)
        {
        delete mImgNormal;
        mImgNormal = nullptr;
        }

    if(mImgVulnerable != nullptr)
        {
        delete mImgVulnerable;
        mImgVulnerable = nullptr;
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

QImage Ghost::getImage()
{
    if(isVulnerable())
        return(getVulnerableImage());
    else
        return(getNormalImage());
}

QString &Ghost::getName() const
{
    return(const_cast<Ghost &>(*this).msName);
}

QSize Ghost::getSize() const
{
    return(QSize(18, 18));
}

bool Ghost::isVulnerable() const
{
    return(mbVulnerable);
}

void Ghost::render(qint64 frame, QPainter &refPainter)
{
    Q_UNUSED(frame);

    refPainter.save();

    refPainter.drawImage(QRectF(getTopLeft(), getSize()), getImage());

    refPainter.restore();
}

void Ghost::revive()
{ }

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
