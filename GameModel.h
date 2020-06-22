#pragma once

#include "Fruit.h"
#include "Ghost.h"
#include "Observable.h"
#include "Piece.h"
#include "PacMan.h"

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
                        unsigned muiCurrentScore, muiHighScore, muiLevel;
                    public:
                        GameModel();

                        unsigned getCurrentScore() const;
                        unsigned getHighScore() const;
                        unsigned getLevel() const;
                        void setCurrentScore(const unsigned uiCurrentScore);
                        void setHighScore(const unsigned uiHighScore);
                        void setLevel(const unsigned uiLevel);
                    };
                }
            }
        }
    }
}
