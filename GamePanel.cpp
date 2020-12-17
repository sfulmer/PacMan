#include "GamePanel.h"
#include "GameWindow.h"
#include "Ghost.h"
#include "PacManApp.h"
#include "Piece.h"
#include <QDebug>
#include <QFontDatabase>
#include <QPaintEvent>
#include <QPainter>

using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::model;
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

qint64 GamePanel::getFrame()
{
    return(miFrame);
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

void GamePanel::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
        {
        case Qt::Key_Space:
            if(getFrame() < 0)
                start();
            break;
        case Qt::Key_Left:
            if(getFrame() > 0)
                getModel().getPacMan().setDirection(MoveablePiece::Direction::West);

            break;
        case Qt::Key_Right:
            if(getFrame() > 0)
                getModel().getPacMan().setDirection(MoveablePiece::Direction::East);

            break;
        case Qt::Key_Up:
            if(getFrame() > 0)
                getModel().getPacMan().setDirection(MoveablePiece::Direction::North);

            break;
        case Qt::Key_Down:
            if(getFrame() > 0)
                getModel().getPacMan().setDirection(MoveablePiece::Direction::South);

            break;
        default:
            break;
        }
}

void GamePanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    painter.save();

    painter.fillRect(event->rect(), QColor(0, 0, 0));

    painter.drawImage(QRectF(event->rect().x(), event->rect().y() + 30 + getModel().getVerticalSpacing(), 512, 512), getGameBoardImage());

    for(const Piece *ptrPiece : getModel().getPieces())
        {
        Piece &refPiece = const_cast<Piece &>(*ptrPiece);

        refPiece.render(getFrame(), painter);
        }

    for(const Fruit *ptrFruit : getModel().getFruit())
        {
        Fruit &refFruit = const_cast<Fruit &>(*ptrFruit);

        refFruit.render(getFrame(), painter);
        }

    for(const Ghost *ptrGhost : getModel().getGhosts())
        {
        Ghost &refGhost = const_cast<Ghost &>(*ptrGhost);

        refGhost.render(getFrame(), painter);
        }

    getModel().getPacMan().render(getFrame(), painter);

    painter.setPen(QPen(QColor(255,255,255)));
    painter.setFont(getGameFont());

    painter.drawText(QRectF(50, 25, 75, 40), Qt::AlignHCenter, tr("1-Up"));
    painter.drawText(QRectF(50, 40, 75, 55), Qt::AlignHCenter, QString("%1").arg(getModel().getOneUps()));
    painter.drawText(QRectF(125, 25, 150, 40), Qt::AlignHCenter, tr("Hi-Score"));
    painter.drawText(QRectF(125, 40, 150, 55), Qt::AlignHCenter, QString("%1").arg(getModel().getHighScore()));

    if((getFrame() >= 0) && (getFrame() < 15))
        {
        painter.setPen(QPen(QColor(255 * ((15 - getFrame()) / 15),255 * ((15 - getFrame()) / 15),255 * ((15 - getFrame()) / 15))));

        painter.drawText(QRectF(0, 560 + getModel().getVerticalSpacing(), event->rect().width(), 25), Qt::AlignHCenter, tr("Ready"));
        }
    else if(getFrame() < 0)
        painter.drawText(QRectF(0, 560 + getModel().getVerticalSpacing(), event->rect().width(), 25), Qt::AlignHCenter, tr("Press Space Bar to Begin game"));

    painter.restore();
}

GamePanel::GamePanel(GameWindow *parent)
    :   GamePanel(parent, static_cast<PacManApp *>(qApp)->getController())
{ }

GamePanel::GamePanel(GameWindow *parent, PacManController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mImgGameBoard(":/images/GameBoard.jpg")
    ,   miFrame(-1)
    ,   mPtrGameFont(nullptr)
    ,   mTimerEvents(nullptr)
{
    initPanel();
}

void GamePanel::doFrame()
{
    miFrame++;

    repaint();
}

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
