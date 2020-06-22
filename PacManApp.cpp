#include "PacManApp.h"

using namespace net::draconia::games::pacman;

void PacManApp::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        mLstArgs.append(argv[iLoop]);
}

void PacManApp::showMainWindow()
{
    getMainWindow().show();
}

PacManApp::PacManApp(int argc, char *argv[])
    :   QApplication(argc, argv)
    ,   mWndGame(nullptr)
    ,   mObjController(*this)
{
    setArguments(argc, argv);
}

int PacManApp::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

void PacManApp::exit()
{
    getMainWindow().close();
}

QList<QString> &PacManApp::getArguments() const
{
    return(const_cast<PacManApp &>(*this).mLstArgs);
}

PacManController &PacManApp::getController()
{
    return(mObjController);
}

GameWindow &PacManApp::getMainWindow()
{
    return(mWndGame);
}
