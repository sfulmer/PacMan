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
                    class Liveable : virtual public Observable
                    {
                        bool mbAlive;
                        unsigned muiLives;
                    public:
                        Liveable(const unsigned uiLives = 0);
                        Liveable(const Liveable &refCopy);
                        Liveable(Liveable &refToMove);

                        virtual void die() = 0;
                        unsigned getLives() const;
                        bool isAlive() const;
                        virtual void revive() = 0;
                        void setAlive(const bool bAlive);
                        void setLives(const unsigned uiLives);
                    };
                }
            }
        }
    }
}
