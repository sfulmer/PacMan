#include "GamePanel.h"
#include "GameWindow.h"
#include "Ghost.h"
#include "PacManApp.h"
#include <QDebug>
#include <QFontDatabase>
#include <QPaintEvent>
#include <QPainter>

using net::draconia::games::pacman::PacManController;
using net::draconia::games::pacman::model::Ghost;
using namespace net::draconia::games::pacman::ui;

PacManController &GamePanel::getController()
{
    return(mRefController);
}

QTimer *GamePanel::getEventTimer()
{
    if(mTimerEvents == nullptr)
        mTimerEvents = new QTimer(this);

    return(mTimerEvents);
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

GameModel &GamePanel::getModel()
{
    return(getController().getModel());
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

    for(const Ghost *ptrGhost : getModel().getGhosts())
        {
        Ghost &refGhost = const_cast<Ghost &>(*ptrGhost);

        painter.drawImage(QRectF(refGhost.getX(), refGhost.getY(), 18, 18), refGhost.getImage());
        }

    painter.restore();
}

GamePanel::GamePanel(GameWindow *parent)
    :   GamePanel(parent, static_cast<PacManApp *>(qApp)->getController())
{ }

GamePanel::GamePanel(GameWindow *parent, PacManController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mImgGameBoard(":/images/GameBoard.jpg")
    ,   mPtrGameFont(nullptr)
{
    initPanel();
}

void GamePanel::doFrame()
{ }

QSize GamePanel::sizeHint() const
{
    return(QSize(512, 650));
}

void GamePanel::start()
{
    getModel().setStarted(true);

    connect(getEventTimer(), &QTimer::timeout, this, &GamePanel::doFrame);
    getEventTimer()->start(500);
}
