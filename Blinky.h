#pragma once

#include "Ghost.h"

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
                    class Blinky : public Ghost
                    {
                    public:
                        Blinky(const int iX = 0, const int iY = 0);
                        Blinky(const Blinky &refCopy);
                        Blinky(Blinky &refToMove);

                        virtual void executeAI();
                    };
                }
            }
        }
    }
}
