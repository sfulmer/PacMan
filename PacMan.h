#pragma once

#include "Liveable.h"
#include "MoveablePiece.h"
#include <QImage>

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

                    class PacMan : public Liveable, public MoveablePiece
                    {
                        bool mbPoweredUp;
                        int miSeconds;
                        QImage *mPtrImage;
                        unsigned muiLives;
                    public:
                        PacMan(const int iX = -1, const int iY = -1, const Direction eDirection = NoDirection, const unsigned uiLives = 3);
                        PacMan(const PacMan&refCopy);
                        PacMan(PacMan &refToMove);
                        ~PacMan();

                        virtual void collided(Piece &refCollider);
                        virtual void die();
                        PacManController &getController();
                        GameModel &getGameModel();
                        virtual QImage getImage();
                        int getSeconds() const;
                        bool isPoweredUp() const;
                        virtual void revive();
                        void setPoweredUp(const bool bPoweredUp);
                        void setSeconds(const int iSeconds);
                    };
                }
            }
        }
    }
}
