#include "game.h"
#include "ui_game.h"
#include "animatable/star.h"
#include <QtWidgets>

Game::Game(int w, int h, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    setFixedSize(w, h);

    QGraphicsScene *scene = new QGraphicsScene( this );

    for (int i=0;i<100;i++) {
        Star *sky = new Star(w, h);
        scene->addItem(sky);
    }

    QGraphicsView *view = new QGraphicsView( scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(Qt::black);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->show();

    setCentralWidget( view );

    QTimer *timer= new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000 / 30);
}

Game::~Game()
{
    delete ui;
}

