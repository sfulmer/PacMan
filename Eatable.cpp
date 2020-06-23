#include "Eatable.h"

using namespace net::draconia::games::pacman::model;

Eatable::Eatable()
    :   Observable()
    ,   mbEaten(false)
{ }

Eatable::Eatable(const Eatable &refCopy)
    :   Observable(refCopy)
    ,   mbEaten(refCopy.isEaten())
{ }

Eatable::Eatable(Eatable &refToMove)
    :   Observable(refToMove)
    ,   mbEaten(refToMove.isEaten())
{ }

bool Eatable::isEaten() const
{
    return(mbEaten);
}

void Eatable::setEaten(const bool bEaten)
{
    mbEaten = bEaten;

    setChanged();
    notifyObservers("Eaten");
}
