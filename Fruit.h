#pragma once

#include "Eatable.h"
#include "Piece.h"

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
                    public:
                        Fruit(const int iX = -1, const int iY = -1);
                        Fruit(const Fruit &refCopy);
                        Fruit(Fruit &refToMove);

                        virtual void collided(Piece &refCollider);
                    };
                }
            }
        }
    }
}
