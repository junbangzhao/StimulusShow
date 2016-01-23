#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singlereaction.h"
#include "QDesktopWidget"
#include "QtDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExp1_triggered()
{
    SingleReaction *w;
    w = new SingleReaction();
    QDesktopWidget *desktop = QApplication::desktop();
    QRect screen = desktop->screenGeometry();
    qDebug() << screen;
    //w->setGeometry(screen);
    w->show();
}
