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
                class PacManController;

                namespace model
                {
                    class GameModel;

                    class PacDot : public Eatable, public Piece
                    {
                    public:
                        PacDot(const int iX = -1, const int iY = -1);
                        PacDot(const PacDot &refCopy);
                        PacDot(PacDot &refToMove);

                        virtual void collided(Piece &refCollider);

                        PacManController &getController();
                        GameModel &getModel();
                    };
                }
            }
        }
    }
}
