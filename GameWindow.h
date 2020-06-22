#pragma once

#include "GamePanel.h"
#include "PacManController.h"
#include <QMainWindow>

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
                    protected:
                        PacManController &getController();
                        GamePanel *getMainPanel();
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
