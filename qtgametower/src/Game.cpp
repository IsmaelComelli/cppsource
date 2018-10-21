#include "include/Game.h"
#include <QGraphicsScene>
#include <QGraphicsView>


Game::Game()
    : QGraphicsView(),
    scene(new QGraphicsScene(this)),
    tower(new Tower())
    {
    // size of the view
    setFixedSize(800,600);

    // add scene
    setScene(scene);

    //add tower to the scene
    scene->addItem(tower);
    }

Game::~Game()
    {
    delete scene;
    delete tower;
    }