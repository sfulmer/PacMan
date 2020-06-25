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
                        Clyde();
                        Clyde(const Clyde &refCopy);
                        Clyde(Clyde &refToMove);

                        virtual void executeAI();
                    };
                }
            }
        }
    }
}
