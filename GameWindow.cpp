#include "GameWindow.h"
#include "PacManApp.h"
#include <QCloseEvent>
#include <QMenuBar>

using namespace net::draconia::games::pacman;
using namespace net::draconia::games::pacman::ui;

void GameWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void GameWindow::exitClicked()
{
    getController().exit();
}

PacManController &GameWindow::getController()
{
    return(mRefController);
}

QAction *GameWindow::getExitAction()
{
    if(mActExit == nullptr)
        {
        mActExit = new QAction("E&xit...", this);

        connect(mActExit, &QAction::triggered, this, &GameWindow::exitClicked);
        }

    return(mActExit);
}

GamePanel *GameWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        {
        mPnlMain = new GamePanel(this, getController());

        mPnlMain->setFocus(Qt::FocusReason::ActiveWindowFocusReason);
        }

    return(mPnlMain);
}

QMenu *GameWindow::getPacManMenu()
{
    if(mMnuPacMan == nullptr)
        {
        mMnuPacMan = new QMenu("&Pac-Man");

        mMnuPacMan->addAction(getExitAction());
        }

    return(mMnuPacMan);
}

void GameWindow::initControls()
{
    setMinimumSize(QSize(512, 550));

    setCentralWidget(getMainPanel());
}

void GameWindow::initMenus()
{
    QMenuBar *mMnuBar = menuBar();

    if(mMnuBar == nullptr)
        mMnuBar = new QMenuBar(this);

    mMnuBar->addMenu(getPacManMenu());

    setMenuBar(mMnuBar);
}

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
    ,   mActExit(nullptr)
    ,   mMnuPacMan(nullptr)
{
    initWindow();
}
