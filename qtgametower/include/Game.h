#ifndef GAME_H
#define GAME_H

#include "include/Tower.h"
#include <QGraphicsView>

class Game : public QGraphicsView
    {
    public:
        Game();
        ~Game();

    private:
        QGraphicsScene * scene;
        Tower * tower;
    };
#endif // GAME_H