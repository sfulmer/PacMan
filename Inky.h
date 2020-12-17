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
                    class Inky : public Ghost
                    {
                    public:
                        Inky(const int iX = 0, const int iY = 0);
                        Inky(const Inky &refCopy);
                        Inky(Inky &refToMove);

                        virtual void executeAI();
                    };
                }
            }
        }
    }
}
