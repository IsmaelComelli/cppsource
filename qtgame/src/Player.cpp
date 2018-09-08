#include "include/Player.h"
#include "include/Bullet.h"
#include "include/Enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QDebug>

Player::Player(QGraphicsItem * parent)
    : QGraphicsRectItem(parent),
    bulletSound(new QMediaPlayer())
    {
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));
    }

void Player::keyPressEvent(QKeyEvent * event)
    {
    if (event->key() == Qt::Key_Left)
        {
        if (pos().x() > 0)
            {
            setPos(x()-10, y());
            }
        }
    else if (event->key() == Qt::Key_Right)
        {
        if (pos().x() < (scene()->width() - rect().width()))
            {
            setPos(x()+10, y());
            }
        }
    else if (event->key() == Qt::Key_Up)
        {
        if (pos().y() > 0)
            {
            setPos(x(), y()-10);
            }
        }
    else if (event->key() == Qt::Key_Down)
        {
        if (pos().y() < (scene()->height() - rect().height()))
            {
            setPos(x(), y()+10);
            }        
        }
    else if (event->key() == Qt::Key_Space)
        {
        // to fix. Play bullet sound.
        bulletSound->play();
        bulletSound->setPosition(0);     
        bulletSound->stop();

        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
        }
    }

void Player::spawn()
    {
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    }