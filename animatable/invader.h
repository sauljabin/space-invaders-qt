#ifndef INVADER_H
#define INVADER_H

#include <QGraphicsItem>

class Invader : public QGraphicsItem {
public:
    Invader(int x, int y);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void advance(int step) override;
    ~Invader();
    void destroy();

private:
    QColor color;
    int frame;
    bool destroyable;
};

#endif // INVADER_H
