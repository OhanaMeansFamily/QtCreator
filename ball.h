#ifndef BALL_H
#define BALL_H

#include "coordinate.h"
#include <QPainter>
#include "brick.h"
#include "paddle.h"

class Ball
{

public:
    Ball();
    Ball(Coordinate coordinate);
    Ball(Coordinate coordinate,
        unsigned int radius);
    Ball(Coordinate coordinate,
        unsigned int radius,
        double xVelocity,
        double yVelocity);

    ~Ball();

    void render(QPainter &painter, Brick *p[6], Paddle *paddle);
    char isCollision();
    void reflectX();
    void reflectY();
    unsigned int getRadius();
    bool isHitBrick(Brick *p[6], int index);

private:


    Coordinate m_coordinate;
    unsigned int m_radius;

    double m_xVelocity;
    double m_yVelocity;
};

#endif // BALL_H
