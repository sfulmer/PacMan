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
                    class Eatable : virtual public Observable
                    {
                        bool mbEaten;
                    public:
                        Eatable();
                        Eatable(const Eatable &refCopy);
                        Eatable(Eatable &refToMove);

                        bool isEaten() const;
                        void setEaten(const bool bEaten);
                    };
                }
            }
        }
    }
}
