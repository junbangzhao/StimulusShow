#include "singlereaction.h"
#include "ui_singlereaction.h"
#include "QKeyEvent"
#include "qapplication.h"
#include "QPainter"
#include "QtDebug"
#include "vector"


SingleReaction::SingleReaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleReaction)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::MaximizeUsingFullscreenGeometryHint);
    //setCursor(Qt::BlankCursor);
    timer_fix = new QTimer(this);
    timer_target = new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    //timer->start(88);
    ui->label->move(width()/2-ui->label->width()/2,height()/2-ui->label->height()/2);
    ui->label->hide();
    ui->pushButton->hide();
    ui->line_H->resize(21,1);
    ui->line_V->resize(1,21);
    ui->line_H->move(width()/2-ui->line_H->width()/2,height()/2-ui->line_H->height()/2);
    ui->line_V->move(width()/2-ui->line_V->width()/2,height()/2-ui->line_V->height()/2);
    ui->line_H->hide();
    ui->line_V->hide();

    vector<int> vecTarget;
    for (int i = 0; i < 10; i++)


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
        connect(timer_fix,SIGNAL(timeout()),this,SLOT(timerUpdate()));
        timer_fix->start(500);
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

    ui->line_H->show();
    ui->line_V->show();
    timer_fix->stop();

    timer_target->start(1000);
    connect(timer_target,SIGNAL(timeout()),this,SLOT(targetShow()));
}

void SingleReaction::targetShow()
{
    ui->line_H->hide();
    ui->line_V->hide();
    ui->label->show();
    timer_target->stop();
}
