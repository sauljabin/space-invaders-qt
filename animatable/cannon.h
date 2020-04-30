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
    void setMouseX(int xMousePosition);

private:
    int minX;
    int maxX;
    int fixY;
    int xMousePosition;
};

#endif // CANNON_H
