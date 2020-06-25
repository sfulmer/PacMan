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
                        Pinky();
                        Pinky(const Pinky &refCopy);
                        Pinky(Pinky &refToMove);

                        virtual void executeAI();
                    };
                }
            }
        }
    }
}
