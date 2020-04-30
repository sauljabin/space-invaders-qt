#include "star.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>

const int SIZE = 4;
const int ADJUST = -SIZE / 2;
const QRectF BODY = QRectF(ADJUST, ADJUST, SIZE, SIZE);

Star::Star()
{
    xPercent = QRandomGenerator::global()->bounded(-100, 100) / 100.;
    yPercent = QRandomGenerator::global()->bounded(-100, 100) / 100.;
}

void Star::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(BODY);
}

QRectF Star::boundingRect() const
{
    return BODY;
}

QPainterPath Star::shape() const
{
    QPainterPath path;
    return path;
}

void Star::advance(int step)
{
    if (!step)
        return;
    setPos(scene()->width() / 2 * xPercent, scene()->height() / 2 * yPercent);
}

Star::~Star() {}
