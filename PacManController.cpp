#include "PacManApp.h"
#include "PacManController.h"

using namespace net::draconia::games::pacman;

PacManApp &PacManController::getApplication()
{
    return(mRefApp);
}

PacManController::PacManController(PacManApp &refApp)
    :   mRefApp(refApp)
{ }

void PacManController::exit()
{
    getApplication().exit();
}

GameModel &PacManController::getModel()
{
    return(mObjModel);
}
