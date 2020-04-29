#include "game.h"
#include "animatable/star.h"
#include "ui_game.h"
#include <QRandomGenerator>
#include <QtWidgets>

Game::Game(int w, int h, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    setFixedSize(w, h);

    QGraphicsScene* scene = new QGraphicsScene(this);

    for (int i = 0; i < 100; i++) {
        int x = QRandomGenerator::global()->bounded(-w / 2, w / 2);
        int y = QRandomGenerator::global()->bounded(-h / 2, h / 2);

        Star* sky = new Star(x, y);
        scene->addItem(sky);
    }

    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(Qt::black);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    setCentralWidget(view);

    QTimer* timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / 30);
}

Game::~Game() { delete ui; }
