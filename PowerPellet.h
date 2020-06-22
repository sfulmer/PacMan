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
                    class PowerPellet : public Piece
                    {
                    public:
                        PowerPellet(const int iX = -1, const int iY = -1);
                    };
                }
            }
        }
    }
}
