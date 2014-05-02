#ifndef DIALOG_H
#define DIALOG_H

#include "configurationmanager.h"
#include "ball.h"
#include <QDialog>
#include <QTimer>
#include <brick.h>
#include <QPixmap>
#include "paddle.h"

struct QKeyEvent;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
     explicit Dialog(QWidget *parent = 0);
    ~Dialog();


public slots:
    void nextFrame();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *e);


protected:

    void paintEvent(QPaintEvent *event);
    void loadSettings();
    void init();

private:

    Ui::Dialog *ui;
    QTimer *timer;
    Ball *m_ball;
    Brick *m_bricks[6];
    Paddle *m_paddle;
    int m_pressedButton;

};


#endif // DIALOG_H
