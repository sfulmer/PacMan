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
                    class Clyde : public Ghost
                    {
                    public:
                        Clyde(const int iX = 0, const int iY = 0);
                        Clyde(const Clyde &refCopy);
                        Clyde(Clyde &refToMove);

                        virtual void executeAI();
                    };
                }
            }
        }
    }
}
