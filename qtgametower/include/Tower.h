#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>

const int NR_POLYGON_POINTS = 8;
const int POLYGON_SCALE = 70;

class Tower : public QGraphicsPixmapItem
    {
    public:
        Tower(QGraphicsItem * parent = 0);
        ~Tower();
    private:
        QGraphicsPolygonItem * attack_area;
    };