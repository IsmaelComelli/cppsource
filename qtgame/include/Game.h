#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>

class QGraphicsScene;
class Player;
class Score;
class Health;

class Game : public QGraphicsView
    {
    public:
        Game(QWidget * parent = 0);
        ~Game();

        QGraphicsScene * scene;
        Player * player;
        Score * score;
        Health * health;
        QMediaPlaylist * playlist;
        QMediaPlayer * bgMusic;

    private:
        

    };

#endif // GAME_H