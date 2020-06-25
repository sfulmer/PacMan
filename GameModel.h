#pragma once

#include "Fruit.h"
#include "Ghost.h"
#include "Observable.h"
#include "Piece.h"
#include "PacMan.h"
#include <QList>

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
                    class GameModel : public Observable
                    {
                        bool mbStarted;
                        QList<Ghost *> mLstGhosts;
                        QList<Piece *> mLstPieces;
                        PacMan mObjPacMan;
                        unsigned muiCurrentScore, muiHighScore, muiLevel;
                    protected:
                        QList<Ghost *> &getGhostsInternal();
                        QList<Piece *> &getPiecesInternal();
                        void setGhosts(const QList<Ghost *> &lstGhosts);
                        void setPacMan(const PacMan &refPacMan);
                        void setPieces(const QList<Piece *> &lstPieces);
                    public:
                        GameModel();
                        ~GameModel();

                        unsigned getCurrentScore() const;
                        const QList<Ghost *> &getGhosts();
                        unsigned getHighScore() const;
                        unsigned getLevel() const;
                        PacMan &getPacMan() const;
                        const QList<Piece *> &getPieces();
                        bool isStarted() const;
                        void setCurrentScore(const unsigned uiCurrentScore);
                        void setHighScore(const unsigned uiHighScore);
                        void setLevel(const unsigned uiLevel);
                        void setStarted(const bool bStarted);
                    };
                }
            }
        }
    }
}
