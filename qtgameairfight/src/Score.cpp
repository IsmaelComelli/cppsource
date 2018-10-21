#include "include/Score.h"
#include <QColor>
#include <QFont>

Score::Score(QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
    {  
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(QColor(Qt::blue));
    setFont(QFont("Courier", 16));   
    }

void Score::increase()
    {
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    }

int Score::getScore()
    {
    return score;
    }