TEMPLATE += app

QT += gui \
    core \
    widgets \
    multimedia

CONFIG += c++11


HEADERS += include/Player.h \
    include/Bullet.h \
    include/Enemy.h \
    include/Game.h \
    include/Score.h \
    include/Health.h
    
SOURCES += src/Player.cpp \
    src/Bullet.cpp \
    src/Enemy.cpp \
    src/main.cpp \
    src/Game.cpp \
    src/Score.cpp \
    src/Health.cpp

RESOURCES += resources/rc.qrc
