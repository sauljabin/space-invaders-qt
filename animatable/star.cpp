#include "star.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>

const int size = 4;
const int adjust = -size / 2;

Star::Star(int w, int h)
    : x(QRandomGenerator::global()->bounded(-w / 2, w / 2))
    , y(QRandomGenerator::global()->bounded(-h / 2, h / 2))
{
}

void Star::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(adjust, adjust, size, size);
}

QRectF Star::boundingRect() const
{
    return QRectF(adjust, adjust, size, size);
}

QPainterPath Star::shape() const
{
    QPainterPath path;
    path.addRect(adjust, adjust, size, size);
    return path;
}

void Star::advance(int step)
{
    if (!step)
        return;

    setPos(x, y);
}
