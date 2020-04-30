#include "invader.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

const QRectF BODY = QRectF(-25, -25, 50, 50);

Invader::Invader(int x, int y)
{
    setX(x);
    setY(y);
    destroyable = false;
}

QRectF Invader::boundingRect() const
{
    return BODY;
}

QPainterPath Invader::shape() const
{
    QPainterPath path;
    path.addRect(BODY);
    return path;
}

void Invader::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawEllipse(-25, -10, 50, 20);
    painter->drawEllipse(-15, -20, 30, 30);

    if (colorController < 10) {
        painter->setBrush(Qt::red);
    } else if (colorController < 20) {
        painter->setBrush(Qt::blue);
    } else {
        painter->setBrush(Qt::cyan);
    }

    painter->drawEllipse(-10, -5, 20, 10);
}

void Invader::advance(int step)
{
    if (!step)
        return;

    colorController++;
    advanceController++;

    if (colorController >= 30) {
        colorController = 0;
    }

    if (advanceController >= 400) {
        advanceController = 0;
    }

    if (advanceController < 100) {

        setX(x() + 1);
    } else if (advanceController < 200) {
        setY(y() + 1);
    } else if (advanceController < 300) {
        setX(x() - 1);
    } else if (advanceController < 400) {
        setY(y() + 1);
    }

    if (destroyable) {
        scene()->removeItem(this);
        delete this;
        return;
    }
}

void Invader::destroy()
{
    destroyable = true;
}

Invader::~Invader() {}
