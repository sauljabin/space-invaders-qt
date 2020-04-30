#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsItem>

class Cannon : public QGraphicsItem {
public:
    Cannon();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void advance(int step) override;
    void setMouseX(int xMousePosition);
    void shoot();
    ~Cannon();

private:
    int xMousePosition;
    int getFixY();
    int getMaxX();
    int getMinX();
};

#endif // CANNON_H
