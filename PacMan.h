#pragma once

#include "MoveablePiece.h"

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
                    class PacMan : public MoveablePiece
                    {
                        bool mbPoweredUp;
                        int miSeconds;
                        unsigned muiLives;
                    public:
                        PacMan(const int iX = -1, const int iY = -1, const Direction eDirection = NoDirection, const unsigned uiLives = 3, const int iSeconds = -1);
                    };
                }
            }
        }
    }
}
