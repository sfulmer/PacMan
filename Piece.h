#pragma once

#include "Observable.h"

using net::draconia::util::Observable;

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
                    class Piece : virtual public Observable
                    {
                        int miX, miY;
                        unsigned muiPoints;
                    public:
                        Piece(const int iX = -1, const int iY = -1, const unsigned uiPoints = 0);
                        Piece(const Piece &refCopy);
                        Piece(Piece &refToMove);
                        virtual ~Piece() { }

                        unsigned getPoints() const;
                        int getX() const;
                        int getY() const;
                        void setPoints(const unsigned uiPoints);
                        void setX(const int iX);
                        void setY(const int iY);

                        virtual void collided(Piece &refCollider) = 0;
                    };
                }
            }
        }
    }
}
