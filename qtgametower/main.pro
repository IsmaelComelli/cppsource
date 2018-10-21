TEMPLATE += app

QT += gui \
    core \
    widgets

CONFIG += c++11

HEADERS += include/Game.h \
        include/Tower.h

SOURCES += src/main.cpp \
        src/Game.cpp \
        src/Tower.cpp

RESOURCES += resources/res.qrc
