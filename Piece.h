#pragma once

#include "Observable.h"
#include <QImage>
#include <QPainter>

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

                        virtual void collided(Piece &refCollider) = 0;
                        virtual QImage getImage() = 0;
                        unsigned getPoints() const;
                        virtual QSize getSize() const = 0;
                        QPoint getTopLeft() const;
                        int getX() const;
                        int getY() const;
                        virtual void render(qint64 frame, QPainter &refPainter) = 0;
                        void setPoints(const unsigned uiPoints);
                        void setX(const int iX);
                        void setY(const int iY);
                    };
                }
            }
        }
    }
}
