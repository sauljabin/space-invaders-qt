#include "game.h"
#include "ui_game.h"
#include <QtWidgets>

#include <QDebug>

Game::Game(int w, int h, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    setFixedSize(w, h);

    QGraphicsScene* scene = new QGraphicsScene(this);

    for (int i = 0; i < 120; i++) {
        Star* sky = new Star(w, h);
        scene->addItem(sky);
    }

    cannon = new Cannon(w, h);
    scene->addItem(cannon);

    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(Qt::black);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    setCentralWidget(view);
    installEventFilter(this);

    QTimer* timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / 30);
    qInfo("Inicia aplicación");
}

Game::~Game() { delete ui; }

bool Game::eventFilter(QObject*, QEvent* ev)
{
    if (ev->type() == QEvent::HoverMove) {
        QMouseEvent* mouseEvent = (QMouseEvent*)ev;
        if (mouseEvent->type() == QMouseEvent::HoverMove) {
            int mCursorX = mouseEvent->x();
            cannon->setMouseX(mCursorX);
        }
    }
    return false;
}
