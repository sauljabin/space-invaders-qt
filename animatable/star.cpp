#include "star.h"

#include <QPainter>
#include <QStyleOption>

const int size = 4;
const int adjust = -size / 2;

Star::Star(int x, int y)
{
    setX(x);
    setY(y);
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
