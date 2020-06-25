#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "GameModel.h"
#include "PacDot.h"
#include "Pinky.h"

using namespace net::draconia::games::pacman::model;

QList<Ghost *> &GameModel::getGhostsInternal()
{
    if(mLstGhosts.isEmpty())
        setGhosts(  {   new Blinky()
                    ,   new Clyde()
                    ,   new Inky()
                    ,   new Pinky()});

    return(mLstGhosts);
}

QList<Piece *> &GameModel::getPiecesInternal()
{
    if(mLstPieces.isEmpty())
        {
        QList<Piece *> lstPieces;

        for(unsigned uiXMax = 240, uiX = 30; uiX < uiXMax; uiX += 18)
            {
            lstPieces.append(new PacDot(uiX, 55));
            lstPieces.append(new PacDot(uiX, 365));
            }

        for(unsigned uiXMax = 490, uiX = 282; uiX < uiXMax; uiX += 18)
            {
            lstPieces.append(new PacDot(uiX, 55));
            lstPieces.append(new PacDot(uiX, 365));
            }

        for(unsigned uiXMax = 490, uiX = 30; uiX < uiXMax; uiX += 18)
            {
            lstPieces.append(new PacDot(uiX, 120));
            lstPieces.append(new PacDot(uiX, 515));
            }

        for(unsigned uiXMax = 125, uiX = 30; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 170));

        for(unsigned uiXMax = 240, uiX = 174; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 170));

        for(unsigned uiXMax = 340, uiX = 282; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 170));

        for(unsigned uiXMax = 490, uiX = 390; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 170));

        for(unsigned uiXMax = 350, uiX = 174; uiX < uiXMax; uiX += 18)
            {
            lstPieces.append(new PacDot(uiX, 220));
            lstPieces.append(new PacDot(uiX, 315));
            }

        for(unsigned uiXMax = 190, uiX = 12; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 265));

        for(unsigned uiXMax = 500, uiX = 336; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 265));

        for(unsigned uiXMax = 80, uiX = 30; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 415));

        for(unsigned uiXMax = 400, uiX = 120; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 415));

        for(unsigned uiXMax = 490, uiX = 444; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 415));

        for(unsigned uiXMax = 135, uiX = 30; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 465));

        for(unsigned uiXMax = 240, uiX = 174; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 465));

        for(unsigned uiXMax = 340, uiX = 282; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 465));

        for(unsigned uiXMax = 490, uiX = 390; uiX < uiXMax; uiX += 18)
            lstPieces.append(new PacDot(uiX, 465));

        for(unsigned uiYMax = 105, uiY = 73; uiY < uiYMax; uiY += 15)
            {
            lstPieces.append(new PacDot(30, uiY));
            lstPieces.append(new PacDot(120, uiY));
            lstPieces.append(new PacDot(228, uiY));
            lstPieces.append(new PacDot(282, uiY));
            lstPieces.append(new PacDot(390, uiY));
            lstPieces.append(new PacDot(480, uiY));
            }

        for(unsigned uiYMax = 160, uiY = 137; uiY < uiYMax; uiY += 16)
            {
            lstPieces.append(new PacDot(30, uiY));
            lstPieces.append(new PacDot(120, uiY));
            lstPieces.append(new PacDot(174, uiY));
            lstPieces.append(new PacDot(336, uiY));
            lstPieces.append(new PacDot(390, uiY));
            lstPieces.append(new PacDot(480, uiY));
            }

        for(unsigned uiYMax = 210, uiY = 186; uiY < uiYMax; uiY += 17)
            {
            lstPieces.append(new PacDot(120, uiY));
            lstPieces.append(new PacDot(228, uiY));
            lstPieces.append(new PacDot(282, uiY));
            lstPieces.append(new PacDot(390, uiY));
            }

        setPieces(lstPieces);
        }

    return(mLstPieces);
}

void GameModel::setGhosts(const QList<Ghost *> &lstGhosts)
{
    mLstGhosts = lstGhosts;

    setChanged();
    notifyObservers("Ghosts");
}

void GameModel::setPacMan(const PacMan &refPacMan)
{
    mObjPacMan = refPacMan;

    setChanged();
    notifyObservers("PacMan");
}

void GameModel::setPieces(const QList<Piece *> &lstPieces)
{
    mLstPieces = lstPieces;

    setChanged();
    notifyObservers("Pieces");
}

GameModel::GameModel()
    :   Observable()
{ }

GameModel::~GameModel()
{
    if(!getPiecesInternal().isEmpty())
        {
        for(Piece *ptrPiece : getPiecesInternal())
            delete ptrPiece;

        getPiecesInternal().clear();
        }
}

unsigned GameModel::getCurrentScore() const
{
    return(muiCurrentScore);
}

const QList<Ghost *> &GameModel::getGhosts()
{
    return(getGhostsInternal());
}

unsigned GameModel::getHighScore() const
{
    return(muiHighScore);
}

unsigned GameModel::getLevel() const
{
    return(muiLevel);
}

PacMan &GameModel::getPacMan() const
{
    return(const_cast<GameModel &>(*this).mObjPacMan);
}

const QList<Piece *> &GameModel::getPieces()
{
    return(getPiecesInternal());
}

bool GameModel::isStarted() const
{
    return(mbStarted);
}

void GameModel::setCurrentScore(const unsigned uiCurrentScore)
{
    muiCurrentScore = uiCurrentScore;

    setChanged();
    notifyObservers("CurrentScore");
}

void GameModel::setHighScore(const unsigned uiHighScore)
{
    muiHighScore = uiHighScore;

    setChanged();
    notifyObservers("HighScore");
}

void GameModel::setLevel(const unsigned uiLevel)
{
    muiLevel = uiLevel;

    setChanged();
    notifyObservers("Level");
}

void GameModel::setStarted(const bool bStarted)
{
    mbStarted = bStarted;

    setChanged();
    notifyObservers("Started");
}
