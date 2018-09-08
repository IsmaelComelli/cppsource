#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsPixmapItem
    {
    Q_OBJECT

    public:
        Bullet(QGraphicsItem * parent = 0);
        virtual ~Bullet();

    public slots:
        void move();
    };