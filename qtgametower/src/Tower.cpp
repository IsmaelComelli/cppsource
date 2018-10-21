#include "include/Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsScale>

#include <QDebug>

Tower::Tower(QGraphicsItem * parent)
    : QGraphicsPixmapItem(parent),
    attack_area(new QGraphicsPolygonItem(this))
    {
    // add images
    setPixmap(QPixmap(":/images/tower.png").scaled(70,70));

    // set position
    //setPos(100, 100);

    // create vector of points
    QVector<QPointF> polygon_vector(NR_POLYGON_POINTS);
    polygon_vector[0] = QPoint(1,0);
    polygon_vector[1] = QPoint(2,0);
    polygon_vector[2] = QPoint(3,1);
    polygon_vector[3] = QPoint(3,2);
    polygon_vector[4] = QPoint(2,3);
    polygon_vector[5] = QPoint(1,3);
    polygon_vector[6] = QPoint(0,2);
    polygon_vector[7] = QPoint(0,1);

    QVector<QPointF>::iterator it = polygon_vector.begin();
    // scale points
    for (; it < polygon_vector.end(); ++it)
        {
        *it *= POLYGON_SCALE;
        }

    // create polygon
    QPolygonF polygon(polygon_vector);
    attack_area->setPolygon(polygon);

    //center polygon
    QPointF poly_center(1.5, 1.5);
    poly_center *= POLYGON_SCALE;
    poly_center = mapToScene(poly_center);

    QPointF tower_center(x() + this->pixmap().width() / 2, y() + this->pixmap().height() / 2);
    QLineF line(poly_center, tower_center);
    attack_area->setPos(x() + line.dx(), y() + line.dy());
    }

Tower::~Tower()
    {

    }