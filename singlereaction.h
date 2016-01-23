#ifndef SINGLEREACTION_H
#define SINGLEREACTION_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class SingleReaction;
}

class SingleReaction : public QWidget
{
    Q_OBJECT

public:
    explicit SingleReaction(QWidget *parent = 0);
    ~SingleReaction();
    void keyPressEvent(QKeyEvent *event);
    //void timerEvent(QTimerEvent *);



private slots:
    //void on_pushButton_clicked();
    void timerUpdate();
    void targetShow();

private:
    Ui::SingleReaction *ui;
    int id1,id2;
    QTimer *timer_fix,*timer_target;

};

#endif // SINGLEREACTION_H
