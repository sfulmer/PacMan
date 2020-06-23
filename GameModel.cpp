#include "GameModel.h"

using namespace net::draconia::games::pacman::model;

QList<Ghost> &GameModel::getGhostsInternal()
{
    return(mLstGhosts);
}

QList<Piece *> &GameModel::getPiecesInternal()
{
    return(mLstPieces);
}

void GameModel::setGhosts(const QList<Ghost> &lstGhosts)
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

const QList<Ghost> &GameModel::getGhosts()
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
