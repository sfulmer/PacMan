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
                    class Fruit : public Piece
                    {
                    public:
                        Fruit(const int iX = -1, const int iY = -1);
                    };
                }
            }
        }
    }
}
