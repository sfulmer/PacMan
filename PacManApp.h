#pragma once

#include "GameWindow.h"
#include "PacManController.h"
#include <QApplication>
#include <QList>
#include <QString>

using net::draconia::games::pacman::ui::GameWindow;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace pacman
            {
                class PacManApp : public QApplication
                {
                    GameWindow mWndGame;
                    PacManController mObjController;
                    QList<QString> mLstArgs;
                protected:
                    void setArguments(int argc, char *argv[]);
                    void showMainWindow();
                public:
                    PacManApp(int argc, char *argv[]);
                    int exec();
                    void exit();
                    QList<QString> &getArguments() const;
                    PacManController &getController();
                    GameWindow &getMainWindow();
                };
            }
        }
    }
}
