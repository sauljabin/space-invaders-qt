#ifndef SKY_H
#define SKY_H

#include <QGraphicsItem>

class Star : public QGraphicsItem
{
public:
    Star(int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void advance(int step) override;
    QPainterPath shape() const override;

private:
    int x;
    int y;
};

#endif // SKY_H