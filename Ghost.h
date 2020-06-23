#pragma once

#include "Liveable.h"
#include "MoveablePiece.h"
#include <QString>

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
                    class Ghost : public Liveable, public MoveablePiece
                    {
                    public:
                        enum Color {NoColor = 0, Blue, Red, Pink, Cyan, Orange, Yellow};
                    private:
                        bool mbVulnerable;
                        Color meColor;
                        QString msName;
                    public:
                        Ghost(const int iX = -1, const int iY = -1, const Direction eDirection = NoDirection, const QString &sName = "", const Color eColor = NoColor);
                        Ghost(const Ghost &refCopy);
                        Ghost(Ghost &refToMove);

                        virtual void collided(Piece &refCollider);
                        virtual void die();
                        Color getColor() const;
                        QString &getName() const;
                        bool isVulnerable() const;
                        virtual void revive();
                        void setColor(const Color eColor);
                        void setName(const QString &sName);
                        void setVulnerable(const bool bVulnerable);
                    };
                }
            }
        }
    }
}
