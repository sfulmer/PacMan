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
                    class MoveablePiece : public Piece
                    {
                    public:
                        enum Direction {NoDirection = 0, North, South, East, West};
                    private:
                        Direction meDirection;
                    public:
                        MoveablePiece(const int i = -1, const int iY = -1, const Direction eDirection = NoDirection, const unsigned uiPoints = 0);

                        Direction getDirection() const;
                        void setDirection(const Direction eDirection);
                    };
                }
            }
        }
    }
}
