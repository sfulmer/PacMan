#include "Fruit.h"
#include <QDir>
#include <QFileInfoList>

using namespace net::draconia::games::pacman::model;

QRandomGenerator *Fruit::mPtrRNG = nullptr;

QRandomGenerator *Fruit::getRNG()
{
    if(mPtrRNG == nullptr)
        mPtrRNG = QRandomGenerator::global();

    return(mPtrRNG);
}

Fruit::Fruit(const int iX, const int iY)
    :   Eatable()
    ,   Piece(iX, iY)
    ,   mPtrImage(nullptr)
{ }

Fruit::Fruit(const Fruit &refCopy)
    :   Eatable(refCopy)
    ,   Piece(refCopy)
    ,   mPtrImage(nullptr)
{ }

Fruit::Fruit(Fruit &refToMove)
    :   Eatable(refToMove)
    ,   Piece(refToMove)
    ,   mPtrImage(nullptr)
{
    if(refToMove.mPtrRNG != nullptr)
        {
        delete refToMove.mPtrImage;
        refToMove.mPtrImage = nullptr;
        }
}

Fruit::~Fruit()
{
    if(mPtrImage != nullptr)
        {
        delete mPtrImage;

        mPtrImage = nullptr;
        }
}

void Fruit::collided(Piece &refCollider)
{
    Q_UNUSED(refCollider);
}

QImage Fruit::getImage()
{
    if(mPtrImage == nullptr)
        {
        QDir dirFruit(":/images/fruit");
        QFileInfoList fruits = dirFruit.entryInfoList();
        int iSelectedFruitIndex = getRNG()->generate64() % fruits.size();
        QFileInfo fileFruit = fruits[iSelectedFruitIndex];
        QString sFruitPath = fileFruit.absoluteFilePath();

        mPtrImage = new QImage(sFruitPath);
        }

    return(*mPtrImage);
}

QSize Fruit::getSize() const
{
    return(QSize(15, 15));
}

void Fruit::render(qint64 frame, QPainter &refPainter)
{
    Q_UNUSED(frame);

    refPainter.save();

    refPainter.drawImage(QRectF(getTopLeft(), getSize()), getImage());

    refPainter.restore();
}
