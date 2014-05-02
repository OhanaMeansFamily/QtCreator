#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QKeyEvent>
#include<configurationmanager.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    timer(NULL)
{
    m_pressedButton = 0;
    ui->setupUi(this);
    init();
    //this->update();

}

Dialog::~Dialog()
{
    delete ui;
    if(timer!=NULL){
        delete timer;
    }
    for (int i = 0; i < 6; i++)
    delete m_bricks[i];
    //delete m_paddle;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    m_ball->render(painter, m_bricks, m_paddle);
    m_paddle->render(painter, m_paddle, m_pressedButton);
    for (int i = 0; i < 6; i++)
        if (m_bricks[i]->getHitpoints() > 0) m_bricks[i]->render(painter);
}

void Dialog::nextFrame()
{
    if (m_pressedButton == 1 || m_pressedButton == 0 || m_pressedButton == 2)
    update();
}

void Dialog::init(){

    if(!ConfigurationManager::Instance()->loadConfigurationFile()){
        exit(0);
    }


    this->resize(ConfigurationManager::Instance()->getBoxWidth(),ConfigurationManager::Instance()->getBoxHeight());
    this->setStyleSheet("background-color: #82CAFF;");

    m_ball = new Ball(ConfigurationManager::Instance()->getBallCoordinate(),
                      ConfigurationManager::Instance()->getBallRadius(),
                      ConfigurationManager::Instance()->getBallXSpeed(),
                      ConfigurationManager::Instance()->getBallYSpeed());

     m_bricks[0] = new Brick(0,0,80,0,80,20,0,20, 1);
     m_bricks[1] = new Brick(100,0,180,0,180,20,100,20, 2);
     m_bricks[2] = new Brick(300,0,380,0,380,20,300,20, 1);
     m_bricks[3] = new Brick(400,0,480,0,480,20,400,20, 1);
     m_bricks[4] = new Brick(300, 60, 380, 60, 380, 100, 300, 100, 2);
     m_bricks[5] = new Brick(200,0,280,0,280,20,200,20, 1);


    m_paddle = new Paddle(500, 540, 600, 540, 600, 600, 500, 600 );

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));

    timer->start(32);

}

void Dialog::keyPressEvent(QKeyEvent * e)
{
    if (e->key()==Qt::Key_Left) {
          m_pressedButton = 2;
    } else if (e->key()==Qt::Key_Right) {
          m_pressedButton = 1;
    }
}

void Dialog::keyReleaseEvent(QKeyEvent * e)
{
    if (e->key()==Qt::Key_Left) {
          m_pressedButton = 0;
    } else if (e->key()==Qt::Key_Right) {
        m_pressedButton = 0;
  }
}
