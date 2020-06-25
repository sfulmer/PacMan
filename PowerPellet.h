#pragma once

#include "Eatable.h"
#include "Piece.h"
#include <QImage>

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
                    class PowerPellet : public Eatable, public Piece
                    {
                        QImage *mPtrImage;
                    public:
                        PowerPellet(const int iX = -1, const int iY = -1);
                        PowerPellet(const PowerPellet &refCopy);
                        PowerPellet(PowerPellet &refToMove);
                        ~PowerPellet();

                        virtual void collided(Piece &refCollider);
                        virtual QImage getImage();
                    };
                }
            }
        }
    }
}
