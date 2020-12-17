#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "GameModel.h"
#include "PacDot.h"
#include "Pinky.h"
#include "PowerPellet.h"

using namespace net::draconia::games::pacman::model;

QList<Fruit *> &GameModel::getFruitInternal()
{
    if(mLstFruit.isEmpty())
        setFruit({ new Fruit(245, 310 + getVerticalSpacing()) });

    return(mLstFruit);
}

QList<Ghost *> &GameModel::getGhostsInternal()
{
    if(mLstGhosts.isEmpty())
        setGhosts(  {   new Blinky(0, getVerticalSpacing())
                    ,   new Clyde(0, getVerticalSpacing())
                    ,   new Inky(0, getVerticalSpacing())
                    ,   new Pinky(0, getVerticalSpacing())});

    return(mLstGhosts);
}

QList<Piece *> &GameModel::getPiecesInternal()
{
    if(mLstPieces.isEmpty())
        {
        QList<Piece *> lstPieces;

        for(unsigned uiX : { 30, 48, 66, 84, 102, 120, 138, 156, 174, 192, 210, 228 })
            for(unsigned uiY : { 55, 365 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiX: { 282, 300, 318, 336, 354, 372, 390, 408, 426, 444, 462, 480 })
            for(unsigned uiY : { 55, 365 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiX : { 30, 48, 66, 84, 102, 120, 138, 156, 174, 192, 210, 228, 246, 264, 282, 300, 318, 336, 354, 372, 390, 408, 426, 444, 462, 480 })
            for(unsigned uiY : { 120, 515 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiX : { 30, 48, 66, 84, 102, 120 })
            lstPieces.append(new PacDot(uiX, 170 + getVerticalSpacing()));

        for(unsigned uiX : { 174, 192, 210, 228 })
            lstPieces.append(new PacDot(uiX, 170 + getVerticalSpacing()));

        for(unsigned uiX : { 282, 300, 318, 336 })
            lstPieces.append(new PacDot(uiX, 170 + getVerticalSpacing()));

        for(unsigned uiX : { 390, 408, 426, 444, 462, 480 })
            lstPieces.append(new PacDot(uiX, 170 + getVerticalSpacing()));

        for(unsigned uiX : { 30, 48, 66, 444, 462, 480 })
            if((uiX == 30) || (uiX == 480))
                lstPieces.append(new PowerPellet(uiX - 4, 411 + getVerticalSpacing()));
            else
                lstPieces.append(new PacDot(uiX, 415 + getVerticalSpacing()));

        for(unsigned uiX : { 120, 138, 156, 174, 192, 210, 228, 246, 264, 282, 300, 318, 336, 354, 372, 390 })
            lstPieces.append(new PacDot(uiX, 415 + getVerticalSpacing()));

        for(unsigned uiX : { 30, 48, 66, 84, 102, 120, 174, 192, 210, 228, 282, 300, 318, 336, 390, 408, 426, 444, 462, 480 })
            lstPieces.append(new PacDot(uiX, 465 + getVerticalSpacing()));

        for(unsigned uiY : { 73, 88, 103 })
            for(unsigned uiX : {30, 120, 228, 282, 390, 480 })
                if(((uiX == 30) || (uiX == 480)) && (uiY == 88))
                    lstPieces.append(new PowerPellet(uiX - 4, uiY - 4 + getVerticalSpacing()));
                else
                    lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiY : { 137, 153 })
            for(unsigned uiX : { 30, 120, 174, 336, 390, 480 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiY : { 188, 204, 219, 235, 250, 265 })
            for(unsigned uiX : { 120, 390 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiY : { 282, 299, 316, 333, 350 })
            for(unsigned uiX : { 120, 390 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiY : { 385, 400 })
            for(unsigned uiX : { 30, 120, 228, 282, 390, 480 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiY : { 432, 449 })
            for(unsigned uiX : { 66, 120, 174, 336, 390, 444 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        for(unsigned uiY : { 480, 497 })
            for(unsigned uiX : { 30, 228, 282, 480 })
                lstPieces.append(new PacDot(uiX, uiY + getVerticalSpacing()));

        setPieces(lstPieces);
        }

    return(mLstPieces);
}

void GameModel::setFruit(const QList<Fruit *> &lstFruit)
{
    mLstFruit = lstFruit;

    setChanged();
    notifyObservers("Fruit");
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
    ,   mObjPacMan(245, 405 + getVerticalSpacing())
    ,   muiCurrentScore(0)
    ,   muiHighScore(0)
    ,   muiOneUps(0)
{ }

GameModel::~GameModel()
{
    if(!getFruitInternal().isEmpty())
        {
        for(Piece *ptrFruit : getFruitInternal())
            delete ptrFruit;

        getFruitInternal().clear();
        }


    if(!getGhostsInternal().isEmpty())
        {
        for(Piece *ptrGhost : getGhostsInternal())
            delete ptrGhost;

        getGhostsInternal().clear();
        }

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

const QList<Fruit *> &GameModel::getFruit()
{
    return(getFruitInternal());
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

unsigned GameModel::getOneUps() const
{
    return(muiOneUps);
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

void GameModel::setOneUps(const unsigned int uiOneUps)
{
    muiOneUps = uiOneUps;

    setChanged();
    notifyObservers("OneUps");
}

void GameModel::setStarted(const bool bStarted)
{
    mbStarted = bStarted;

    setChanged();
    notifyObservers("Started");
}

int GameModel::getVerticalSpacing()
{
    return(msiVerticalSpacing);
}
