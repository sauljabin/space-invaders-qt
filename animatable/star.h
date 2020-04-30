#ifndef SKY_H
#define SKY_H

#include <QGraphicsItem>

class Star : public QGraphicsItem {
public:
    Star();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void advance(int step) override;
    ~Star();

private:
    qreal xPercent;
    qreal yPercent;
};

#endif // SKY_H
