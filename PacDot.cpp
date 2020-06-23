#include "GameModel.h"
#include "PacManApp.h"
#include "PacManController.h"
#include "PacDot.h"
#include <QString>

using net::draconia::games::pacman::PacManApp;
using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::model;

PacDot::PacDot(const int iX, const int iY)
    :   Eatable()
    ,   Piece(iX, iY)
{ }

PacDot::PacDot(const PacDot &refCopy)
    :   Eatable(refCopy)
    ,   Piece(refCopy)
{ }

PacDot::PacDot(PacDot &refToMove)
    :   Eatable(refToMove)
    ,   Piece(refToMove)
{ }

void PacDot::collided(Piece &refCollider)
{
    if(QString(typeid(refCollider).name()) == "PacMan")
        {
        setEaten(true);
        }
}

PacManController &PacDot::getController()
{
    return(static_cast<PacManApp *>(qApp)->getController());
}

GameModel &PacDot::getModel()
{
    return(getController().getModel());
}
