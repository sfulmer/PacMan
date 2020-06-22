#pragma once

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
                    class PacDot : public Piece
                    {
                        bool mbEaten;
                    public:
                        PacDot(const int iX = -1, const int iY = -1, const bool bEaten = false);

                        bool isEaten() const;
                        void setEaten(const bool bEaten);

                        virtual void collided(Piece &refCollider);
                    };
                }
            }
        }
    }
}
