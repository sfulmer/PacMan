#pragma once

#include "GamePanel.h"
#include "PacManController.h"
#include <QAction>
#include <QMainWindow>
#include <QMenu>

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace pacman
            {
                namespace ui
                {
                    class GameWindow : public QMainWindow
                    {
                        Q_OBJECT
                        GamePanel *mPnlMain;
                        PacManController &mRefController;
                        QAction *mActExit;
                        QMenu *mMnuPacMan;
                    protected:
                        void closeEvent(QCloseEvent *event);
                        void exitClicked();
                        PacManController &getController();
                        QAction *getExitAction();
                        GamePanel *getMainPanel();
                        QMenu *getPacManMenu();
                        void initControls();
                        void initMenus();
                        void initWindow();
                    public:
                        GameWindow(QWidget *parent);
                        GameWindow(QWidget *parent, PacManController &refController);
                    };
                }
            }
        }
    }
}
