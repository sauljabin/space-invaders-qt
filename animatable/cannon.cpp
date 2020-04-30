#include "cannon.h"

#include "animatable/bullet.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

const QRectF BODY = QRectF(-30, -15, 60, 30);
const QRectF CANNON = QRectF(-10, -30, 20, 20);
const QRectF POINT = QRectF(-2, -35, 4, 10);

Cannon::Cannon()
{
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

    setY(getFixY());

    if (xMousePosition <= getMinX()) {
        setX(getMinX());
    } else if (xMousePosition >= getMaxX()) {
        setX(getMaxX());
    } else {
        setX(xMousePosition);
    }
}

int Cannon::getFixY()
{
    return scene()->height() / 2 - 23;
}

int Cannon::getMaxX() {
    return scene()->width() / 2 - 40;
}

int Cannon::getMinX() {
    return -scene()->width() / 2 + 40;
}

void Cannon::setMouseX(int xMousePosition)
{
    this->xMousePosition = xMousePosition - getMaxX() - 35;
}

void Cannon::shoot()
{
    Bullet* bullet = new Bullet(x(), y() - 35);
    scene()->addItem(bullet);
}

Cannon::~Cannon() {}
