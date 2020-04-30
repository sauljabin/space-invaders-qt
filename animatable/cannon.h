#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsItem>

class Cannon : public QGraphicsItem {
public:
    Cannon(int w, int h);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void advance(int step) override;

private:
    int minX;
    int maxX;
    int fixY;
};

#endif // CANNON_H
