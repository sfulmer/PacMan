#pragma once

#include "Liveable.h"
#include "MoveablePiece.h"
#include <QImage>
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
                        QImage *mPtrImage;
                        QString msName;
                    public:
                        Ghost(const int iX = -1, const int iY = -1, const Direction eDirection = NoDirection, const QString &sName = "", const Color eColor = NoColor);
                        Ghost(const QString &sName, const Color eColor = NoColor);
                        Ghost(const Ghost &refCopy);
                        Ghost(Ghost &refToMove);
                        ~Ghost();

                        virtual void collided(Piece &refCollider);
                        virtual void die();
                        virtual void executeAI() = 0;
                        Color getColor() const;
                        virtual QImage getImage();
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
