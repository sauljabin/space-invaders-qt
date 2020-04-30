#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "animatable/cannon.h"
#include "animatable/invader.h"
#include "animatable/star.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Game;
}
QT_END_NAMESPACE

class Game : public QMainWindow {
    Q_OBJECT

public:
    Game(int w, int h, QWidget* parent = nullptr);
    ~Game();
    virtual bool eventFilter(QObject* object, QEvent* ev) override;

private:
    Ui::Game* ui;
    Cannon* cannon;
};
#endif // MAINWINDOW_H
