#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>

class Bullet : public QGraphicsItem {
public:
    Bullet(int x, int initialY);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void advance(int step) override;
    ~Bullet();
};

#endif // BULLET_H
