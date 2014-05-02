#include "ball.h"
#include <QDebug>
#include <iostream>

//#include <QSound>


Ball::Ball(Coordinate coordinate):m_coordinate(coordinate){

}

Ball::~Ball(){

}

Ball::Ball(Coordinate coordinate, unsigned int radius):m_coordinate(coordinate), m_radius(radius){

}

Ball::Ball(Coordinate coordinate,
           unsigned int radius,
           double xVelocity,
           double yVelocity):
    m_coordinate(coordinate),
    m_radius(radius),
    m_xVelocity(xVelocity),
    m_yVelocity(yVelocity)
{

}

bool Ball::isHitBrick(Brick *p[6], int index) {

    if (p[index]->getHitpoints() > 0 && m_coordinate.getQtRenderingYCoordinate() < (signed int) p[index]->getY3Coordinate() + m_radius &&
            m_coordinate.getQtRenderingXCoordinate() < (signed int) p[index]->getX2Coordinate() &&
            m_coordinate.getQtRenderingXCoordinate() > (signed int) p[index]->getX1Coordinate()  &&
            m_coordinate.getQtRenderingYCoordinate() > (signed int) p[index]->getY2Coordinate())
        return true;

    return false;

}

//verifies if there is a collision. Returns a 'b' for bottom, 't' for top, 'l' for left, 'r' for right and 'n' for no collision
char Ball::isCollision()
{
    if( m_coordinate.getQtRenderingYCoordinate() > (signed int) (m_coordinate.getFrameHeight() - (signed int) m_radius)){
        return 'b';
    }

    if(m_coordinate.getQtRenderingYCoordinate() < (signed int) m_radius){
        return 't';
    }

    if(m_coordinate.getQtRenderingXCoordinate() > (signed int) (m_coordinate.getFrameWidth()-(signed int) m_radius)){
        return 'r';
    }

    if(m_coordinate.getQtRenderingXCoordinate() < (signed int) m_radius){
        return 'l';
    }
    return 'n';

}

//reflect the ball on the X axis.
void Ball::reflectX()
{
    this->m_xVelocity *= -1;
}

//reflect the ball on the Y axis.
void Ball::reflectY()
{
    this->m_yVelocity *= -1;
}


//renders the ball
void Ball::render(QPainter &painter, Brick *p[6], Paddle *paddle)
{
    char colision = isCollision();
    int index = -1;

    //get index of a brick got hit
    for (int i = 0; i < 6; i++) {
        if (isHitBrick(p, i))   {
            index = i;
            break;
        }
    }
    if (colision!='n') {

        //QSound::play("beep-07.wav");
       // std::cout << paddle->getX1Coordinate() << std::endl;
        switch (colision){
        case 'b':
            if (m_coordinate.getQtRenderingYCoordinate() > paddle->getY3Coordinate()) {
                            reflectY();
                            reflectX();
            }
            else if (index < 0) {
                m_yVelocity = 0;
                m_xVelocity = 0;
            }
            else {
                p[index]->decrementHitpoints();
                reflectX();
                reflectY();
            }
            break;
        case 't':
                if (index < 0) {
                    m_coordinate.setYCoordinate(m_coordinate.getFrameHeight()- this->getRadius());
                    reflectY();
                } else {
                    p[index]->decrementHitpoints();
                    reflectX();
                    reflectY();
                }
            break;
        case 'l':
            if (index < 0) {
                m_coordinate.setXCoordinate(this->getRadius());
                reflectX();
            } else {
                p[index]->decrementHitpoints();
                reflectX();
                reflectY();
            }
            break;
        case 'r':
            if (index < 0) {
                m_coordinate.setXCoordinate(m_coordinate.getFrameWidth()-this->getRadius());
                reflectX();
            } else {
                p[index]->decrementHitpoints();
                reflectX();
                reflectY();
            }
            break;
        }
    } else {
        if (index > 0) {
             p[index]->decrementHitpoints();
             reflectX();
             reflectY();
        } else if (m_coordinate.getQtRenderingYCoordinate() + m_radius > paddle->getY1Coordinate() && m_yVelocity < 0 &&
                   m_coordinate.getQtRenderingXCoordinate() < paddle->getX2Coordinate() &&
                   m_coordinate.getQtRenderingXCoordinate() > paddle->getX1Coordinate()) {
            reflectY();
            reflectX();
        }
    }

    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( Qt::yellow ) );
    painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
                        m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
                        m_radius * 2,
                        m_radius * 2);
    m_coordinate.changeInXCoordinate((int)m_xVelocity);
    m_coordinate.changeInYCoordinate(m_yVelocity);
}

unsigned int Ball::getRadius(){
    return m_radius;
}

