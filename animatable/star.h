#ifndef SKY_H
#define SKY_H

#include <QGraphicsItem>

class Star : public QGraphicsItem {
public:
    Star(int x, int y);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;
};

#endif // SKY_H
