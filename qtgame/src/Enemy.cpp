#include "include/Enemy.h"
#include "include/Player.h"
#include "include/Game.h"
#include "include/Health.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

extern Game * game;

Enemy::Enemy()
    {
    int random_number = rand() % 700;

    setPos(random_number, 0);
    setRect(0,0,100,100);
    
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(200);
    }

void Enemy::move()
    {
    QList<QGraphicsItem *> colliding_items = collidingItems();

    setPos(x(),y()+10);

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
        if (typeid(*(colliding_items[i])) == typeid(Player))
            {
            game->health->decrease();
            scene()->removeItem(this);
            //scene()->removeItem(colliding_items[i]);
            delete this;
            //delete colliding_items[i];
            return;
            }
        }

    if (pos().y() > 600)
        {
        scene()->removeItem(this);
        delete this;
        } 
    }