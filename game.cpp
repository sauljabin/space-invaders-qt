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
    scene->setSceneRect(-w / 2, -h / 2, w, h);

    for (int i = 0; i < 120; i++) {
        Star* sky = new Star();
        scene->addItem(sky);
    }

    cannon = new Cannon();
    scene->addItem(cannon);

    int initX = -300;
    int initY = -300;

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 3; j++) {
            Invader* invader = new Invader(initX + 60 * i, initY + 60 * j);
            scene->addItem(invader);
        }
    }

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
    qInfo() << "Inicia aplicación";
}

Game::~Game() { delete ui; }

bool Game::eventFilter(QObject*, QEvent* ev)
{
    if (ev->type() == QEvent::HoverMove) {
        QMouseEvent* mouseEvent = (QMouseEvent*)ev;
        cannon->setMouseX(mouseEvent->x());
    } else if (ev->type() == QEvent::MouseButtonPress) {
        cannon->shoot();
    }
    return false;
}
