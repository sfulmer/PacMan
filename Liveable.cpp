#include "Liveable.h"

using namespace net::draconia::games::pacman::model;

Liveable::Liveable(const unsigned uiLives)
    :   Observable()
    ,   mbAlive(true)
    ,   muiLives(uiLives)
{ }

Liveable::Liveable(const Liveable &refCopy)
    :   Observable(refCopy)
    ,   mbAlive(refCopy.isAlive())
    ,   muiLives(refCopy.getLives())
{ }

Liveable::Liveable(Liveable &refToMove)
    :   Observable(refToMove)
    ,   mbAlive(refToMove.isAlive())
    ,   muiLives(refToMove.getLives())
{ }

unsigned Liveable::getLives() const
{
    return(muiLives);
}

bool Liveable::isAlive() const
{
    return(mbAlive);
}

void Liveable::setAlive(const bool bAlive)
{
    mbAlive = bAlive;

    setChanged();
    notifyObservers("Alive");
}

void Liveable::setLives(const unsigned int uiLives)
{
    muiLives = uiLives;

    setChanged();
    notifyObservers("Lives");
}
