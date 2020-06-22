#pragma once

#include "PacManController.h"
#include <QWidget>

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
                    class GameWindow;

                    class GamePanel : public QWidget
                    {
                        Q_OBJECT
                        PacManController &mRefController;
                    protected:
                        PacManController &getController();
                        void initControls();
                        void initPanel();
                        void paintEvent(QPaintEvent *event);
                    public:
                        GamePanel(GameWindow *parent);
                        GamePanel(GameWindow *parent, PacManController &refController);
                    signals:

                    };
                }
            }
        }
    }
}
