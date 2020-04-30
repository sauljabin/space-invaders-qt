#include "star.h"

#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>

const int SIZE = 4;
const int ADJUST = -SIZE / 2;

Star::Star(int w, int h)
{
    int x = QRandomGenerator::global()->bounded(-w / 2, w / 2);
    int y = QRandomGenerator::global()->bounded(-h / 2, h / 2);
    setX(x);
    setY(y);
}

void Star::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(ADJUST, ADJUST, SIZE, SIZE);
}

QRectF Star::boundingRect() const
{
    return QRectF(ADJUST, ADJUST, SIZE, SIZE);
}
