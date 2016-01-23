#include "singlereaction.h"
#include "ui_singlereaction.h"
#include "QKeyEvent"
#include "qapplication.h"
#include "QPainter"
#include "QtDebug"


SingleReaction::SingleReaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleReaction)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::MaximizeUsingFullscreenGeometryHint);
    //setCursor(Qt::BlankCursor);
    timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    //timer->start(88);
    ui->label->hide();
    ui->pushButton->hide();
    ui->line_H->setGeometry(100,200,21,1);
    //ui->line_V->setGeometry(frameSize().width()/2,frameSize().height()/2,11,1);
    qDebug() <<frameSize().width();


}

SingleReaction::~SingleReaction()
{
    delete ui;
}

void SingleReaction::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        close();
    switch (event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_Enter:
        connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
        timer->start(500);
        break;
    }
}

/*------------------------------------------
void SingleReaction::on_pushButton_clicked()
{
    //id1 = startTimer(100);
    //id2 = startTimer(200);
}
-------------------------------------------*/

/*-------------------------------------------
void SingleReaction::timerEvent(QTimerEvent *)
{
    if (ui->label->isVisible() == true)
    {
        ui->label->hide();
        killTimer(id1);
        id1 = startTimer(200);
    }
    else
    {
        ui->label->show();
        killTimer(id1);
        id1 = startTimer(100);
    }
}
--------------------------------------------*/

void SingleReaction::timerUpdate()
{
    ui->label->show();
    timer->stop();
}
