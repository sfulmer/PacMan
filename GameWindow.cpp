#include "GameWindow.h"
#include "PacManApp.h"

using namespace net::draconia::games::pacman;
using namespace net::draconia::games::pacman::ui;

PacManController &GameWindow::getController()
{
    return(mRefController);
}

GamePanel *GameWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        mPnlMain = new GamePanel(this, getController());

    return(mPnlMain);
}

void GameWindow::initControls()
{
    setMinimumSize(QSize(512, 550));

    setCentralWidget(getMainPanel());
}

void GameWindow::initMenus()
{ }

void GameWindow::initWindow()
{
    setWindowTitle("Pac-Man");

    initControls();
    initMenus();
}

GameWindow::GameWindow(QWidget *parent)
    :   GameWindow(parent, static_cast<PacManApp *>(qApp)->getController())
{ }

GameWindow::GameWindow(QWidget *parent, PacManController &refController)
    :   QMainWindow(parent)
    ,   mPnlMain(nullptr)
    ,   mRefController(refController)
{
    initWindow();
}
