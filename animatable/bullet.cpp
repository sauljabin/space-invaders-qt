#include "bullet.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

const QRectF BODY = QRectF(-2, -5, 4, 10);
const int SPEED = 15;

Bullet::Bullet(int x, int initialY)
{
    setX(x);
    setY(initialY);
}

QRectF Bullet::boundingRect() const
{
    return BODY;
}

QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addRect(BODY);
    return path;
}

void Bullet::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawRoundRect(BODY, 20, 20);
}

void Bullet::advance(int step)
{
    if (!step)
        return;

    setY(y() - SPEED);

    if (y() <= -scene()->height() / 2) {
        scene()->removeItem(this);
        delete this;
    }
}

Bullet::~Bullet() { qInfo() << "Bala llegó al final de la scene"; }
