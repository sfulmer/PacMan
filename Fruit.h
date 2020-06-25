#pragma once

#include "Eatable.h"
#include "Piece.h"
#include <QImage>
#include <QRandomGenerator>

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace pacman
            {
                namespace model
                {
                    class Fruit : public Eatable, public Piece
                    {
                        static QRandomGenerator *mPtrRNG;

                        QImage *mPtrImage;
                    protected:
                        static QRandomGenerator *getRNG();
                    public:
                        Fruit(const int iX = -1, const int iY = -1);
                        Fruit(const Fruit &refCopy);
                        Fruit(Fruit &refToMove);
                        ~Fruit();

                        virtual void collided(Piece &refCollider);
                        virtual QImage getImage();
                        virtual QSize getSize() const;
                        virtual void render(qint64 frame, QPainter &refPainter);
                    };
                }
            }
        }
    }
}
