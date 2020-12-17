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
                    class Pinky : public Ghost
                    {
                    public:
                        Pinky(const int iX = 0, const int iY = 0);
                        Pinky(const Pinky &refCopy);
                        Pinky(Pinky &refToMove);

                        virtual void executeAI();
                    };
                }
            }
        }
    }
}
