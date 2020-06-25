QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Blinky.cpp \
    Clyde.cpp \
    Eatable.cpp \
    Fruit.cpp \
    GameModel.cpp \
    GamePanel.cpp \
    Ghost.cpp \
    Inky.cpp \
    Liveable.cpp \
    MoveablePiece.cpp \
    Observable.cpp \
    PacDot.cpp \
    PacMan.cpp \
    PacManApp.cpp \
    PacManController.cpp \
    Piece.cpp \
    Pinky.cpp \
    PowerPellet.cpp \
    main.cpp \
    GameWindow.cpp

HEADERS += \
    Blinky.h \
    Clyde.h \
    Eatable.h \
    Fruit.h \
    GameModel.h \
    GamePanel.h \
    GameWindow.h \
    Ghost.h \
    Inky.h \
    Liveable.h \
    MoveablePiece.h \
    Observable.h \
    PacDot.h \
    PacMan.h \
    PacManApp.h \
    PacManController.h \
    Piece.h \
    Pinky.h \
    PowerPellet.h

TRANSLATIONS += \
    PacMan_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    fonts/emulogic.ttf \
    images/GameBoard.jpg \
    images/PacDot.png \
    images/PacMan/Closed.png \
    images/PacMan/Open.png \
    images/PowerPellet.png \
    images/fruit/Apple.png \
    images/fruit/Banana.png \
    images/fruit/Cherry.png \
    images/fruit/Peach.png \
    images/fruit/Pear.png \
    images/fruit/Pretzel.png \
    images/fruit/Strawberry.png \
    images/ghosts/Clyde.png \
    images/ghosts/Inky.png \
    images/ghosts/Normal/Blinky.png \
    images/ghosts/Normal/Clyde.png \
    images/ghosts/Normal/Inky.png \
    images/ghosts/Normal/Pinky.png \
    images/ghosts/Pinky.png \
    images/ghosts/Vulnerable/Blinky.png \
    images/ghosts/Vulnerable/Clyde.png \
    images/ghosts/Vulnerable/Inky.png \
    images/ghosts/Vulnerable/Pinky.png

RESOURCES += \
    PacMan.qrc
