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
                        bool mbVulnerable;
                        QImage *mImgNormal, *mImgVulnerable;
                        QString msName;
                    protected:
                        QImage getNormalImage();
                        QImage getVulnerableImage();
                    public:
                        Ghost(const int iX = -1, const int iY = -1, const Direction eDirection = NoDirection, const QString &sName = "");
                        Ghost(const QString &sName);
                        Ghost(const Ghost &refCopy);
                        Ghost(Ghost &refToMove);
                        ~Ghost();

                        virtual void collided(Piece &refCollider);
                        virtual void die();
                        virtual void executeAI() = 0;
                        virtual QImage getImage();
                        QString &getName() const;
                        virtual QSize getSize() const;
                        bool isVulnerable() const;
                        virtual void render(qint64 frame, QPainter &refPainter);
                        virtual void revive();
                        void setName(const QString &sName);
                        void setVulnerable(const bool bVulnerable);
                    };
                }
            }
        }
    }
}
