#pragma once

#include "GameModel.h"
#include "PacManController.h"
#include <QFont>
#include <QImage>
#include <QSharedPointer>
#include <QTimer>
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
                        QImage mImgGameBoard;
                        QSharedPointer<QFont> mPtrGameFont;
                        QTimer *mTimerEvents;
                    protected:
                        PacManController &getController();
                        QTimer *getEventTimer();
                        QImage &getGameBoardImage();
                        QFont &getGameFont();
                        GameModel &getModel();
                        void initControls();
                        void initPanel();
                        void paintEvent(QPaintEvent *event);
                    public:
                        GamePanel(GameWindow *parent);
                        GamePanel(GameWindow *parent, PacManController &refController);

                        void doFrame();
                        QSize sizeHint() const;
                        void start();
                    signals:
                    };
                }
            }
        }
    }
}
