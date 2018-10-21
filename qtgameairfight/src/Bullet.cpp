#include "include/Bullet.h"
#include "include/Enemy.h"
#include "include/Game.h"
#include "include/Score.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include <QGraphicsItem>

extern Game * game;

Bullet::Bullet(QGraphicsItem * parent)
    : QObject(),
    QGraphicsPixmapItem(parent)
    {
    // draws the bullet
    setPixmap(QPixmap(":/images/bullet.png").scaled(QSize(20,20)));
  

    // connects
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    
    timer->start(50);
    }

Bullet::~Bullet()
    {

    }

void Bullet::move()
    {
    // checks if there are items colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
        if (typeid(*colliding_items[i]) == typeid(Enemy))
            {
            // increases the score
            game->score->increase();
            // removes colliding itens
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // deletes colliding items
            delete colliding_items[i];
            delete this;
            
            return;
            }
        }

    
    // moves bullet up
    setPos(x(), y()-10);

    if (pos().y() < 0)
        {
        scene()->removeItem(this);
        delete this;
        }
    }