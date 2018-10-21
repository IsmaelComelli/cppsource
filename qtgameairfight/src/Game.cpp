#include "include/Game.h"
#include "include/Player.h"
#include "include/Enemy.h"
#include "include/Score.h"
#include "include/Health.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <QImage>
#include <thread>
#include <chrono>


Game::Game(QWidget * parent)
    : QGraphicsView(parent),
    scene(new QGraphicsScene()), // creates scene
    player(new Player()), // creates player
    score(new Score()), // creates score
    health(new Health()),
    playlist(new QMediaPlaylist()),
    bgMusic(new QMediaPlayer())
    {
    scene->setBackgroundBrush(QBrush(QImage(":images/bg.jpg").scaled(800,600)));
    // adds player on the scene
    scene->addItem(player);
    // adds score on the scene
    scene->addItem(score);
    // adds health on the scene
    scene->addItem(health);
    // makes the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // calls the slot to create enemys
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
    // creates a view and add a scene on it
    setScene(scene);
    // desables the scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // fixes the size of the view
    setFixedSize(800, 600);
    //fixes the size of the scene
    scene->setSceneRect(0, 0, 800, 600);
    // sets the position of the player
    player->setPos((scene->width() / 2 - player->pixmap().width() / 2), (scene->height() - player->pixmap().height()));
    health->setPos(700, 0);
    // sets backgound sound
    playlist->addMedia(QUrl("qrc:/sounds/bg.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    bgMusic->setPlaylist(playlist);
    bgMusic->play();
    }

Game::~Game()
    {
    delete scene;
    delete player;
    delete score;
    delete health;
    delete bgMusic;
    }