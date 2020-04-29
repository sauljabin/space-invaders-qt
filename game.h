#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::Game* ui;
};
#endif // MAINWINDOW_H
