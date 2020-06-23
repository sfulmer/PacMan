#pragma once

#include "PacManController.h"
#include <QFont>
#include <QImage>
#include <QSharedPointer>
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
                        QSharedPointer<QFont> mPtrGameFont;
                        QImage mImgFruit, mImgGameBoard, mImgPacDot, mImgPacMan, mImgPowerPellet;
                    protected:
                        PacManController &getController();
                        QImage &getFruitImage();
                        QImage &getGameBoardImage();
                        QFont &getGameFont();
                        QImage &getPacDotImage();
                        QImage &getPacManImage();
                        QImage &getPowerPelletImage();
                        void initControls();
                        void initPanel();
                        void paintEvent(QPaintEvent *event);
                    public:
                        GamePanel(GameWindow *parent);
                        GamePanel(GameWindow *parent, PacManController &refController);

                        QSize sizeHint() const;
                    signals:
                    };
                }
            }
        }
    }
}
