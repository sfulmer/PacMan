#include "GamePanel.h"
#include "GameWindow.h"
#include "PacManApp.h"
#include <QFontDatabase>
#include <QPaintEvent>
#include <QPainter>

using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::ui;

PacManController &GamePanel::getController()
{
    return(mRefController);
}

QImage &GamePanel::getFruitImage()
{
    return(mImgFruit);
}

QImage &GamePanel::getGameBoardImage()
{
    return(mImgGameBoard);
}

QFont &GamePanel::getGameFont()
{
    if(mPtrGameFont.isNull())
        {
        int iId = QFontDatabase::addApplicationFont(":/fonts/emulogic.ttf");
        QString sFamily = QFontDatabase::applicationFontFamilies(iId).at(0);
        mPtrGameFont.reset(new QFont(sFamily));
        }

    return(*mPtrGameFont);
}

QImage &GamePanel::getPacDotImage()
{
    return(mImgPacDot);
}

QImage &GamePanel::getPacManImage()
{
    return(mImgPacMan);
}

QImage &GamePanel::getPowerPelletImage()
{
    return(mImgPowerPellet);
}

void GamePanel::initControls()
{ }

void GamePanel::initPanel()
{
    initControls();
}

void GamePanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    painter.save();

    painter.fillRect(event->rect(), QColor(0, 0, 0));

    painter.drawImage(QRectF(event->rect().x(), event->rect().y() + 30, 512, 512), getGameBoardImage());

    painter.restore();
}

GamePanel::GamePanel(GameWindow *parent)
    :   GamePanel(parent, static_cast<PacManApp *>(qApp)->getController())
{ }

GamePanel::GamePanel(GameWindow *parent, PacManController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mPtrGameFont(nullptr)
    ,   mImgFruit(":/images/fruit.png")
    ,   mImgGameBoard(":/images/GameBoard.jpg")
    ,   mImgPacDot(":/images/pacdot.png")
    ,   mImgPacMan(":/images/pacman.png")
    ,   mImgPowerPellet(":/images/powerpellet.png")
{
    initPanel();
}

QSize GamePanel::sizeHint() const
{
    return(QSize(512, 550));
}
