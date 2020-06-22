#include "GamePanel.h"
#include "GameWindow.h"
#include "PacManApp.h"
#include <QPaintEvent>
#include <QPainter>

using net::draconia::games::pacman::PacManController;
using namespace net::draconia::games::pacman::ui;

PacManController &GamePanel::getController()
{
    return(mRefController);
}

void GamePanel::initControls()
{ }

void GamePanel::initPanel()
{
    //setStyleSheet("background-color: black;");

    initControls();
}

void GamePanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::RenderHint::Antialiasing);

    painter.save();

    painter.fillRect(event->rect(), QColor(0, 0, 0));

    painter.restore();
}

GamePanel::GamePanel(GameWindow *parent)
    :   GamePanel(parent, static_cast<PacManApp *>(qApp)->getController())
{ }

GamePanel::GamePanel(GameWindow *parent, PacManController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
{
    initPanel();
}
