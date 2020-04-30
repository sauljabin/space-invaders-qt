#include "cannon.h"

#include <QPainter>
#include <QStyleOption>

const QRectF BODY = QRectF(-30, -15, 60, 30);
const QRectF CANNON = QRectF(-10, -30, 20, 20);
const QRectF POINT = QRectF(-2, -35, 4, 10);

Cannon::Cannon(int w, int h)
{
    minX = -w / 2 + 40;
    maxX = w / 2 - 40;
    fixY = h / 2 - 23;
    setX(minX);
}

QRectF Cannon::boundingRect() const
{
    return QRectF(-30, -40, 60, 60);
}

QPainterPath Cannon::shape() const
{
    QPainterPath path;
    path.addRect(BODY);
    return path;
}

void Cannon::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::green);
    painter->drawRoundRect(BODY, 20, 20);
    painter->drawRoundRect(CANNON, 20, 20);
    painter->drawRoundRect(POINT, 20, 20);
}

void Cannon::advance(int step)
{
    if (!step)
        return;
    setPos(x() + 1, fixY);
}
