#ifndef PADDLE_H
#define PADDLE_H
#include <QPainter>
#include "configurationmanager.h"

class Paddle
{
public:
    Paddle();
    Paddle(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);

    void render(QPainter &painter, Paddle *p, int pressed);
    int getX1Coordinate();
    int getX2Coordinate();
    int getY1Coordinate();
    int getY2Coordinate();

    int getX3Coordinate();
    int getX4Coordinate();
    int getY3Coordinate();
    int getY4Coordinate();

    void changeX(int change);


    ~Paddle();




private:

    int height;
    int width;
    int coordinateX1;
    int coordinateY1;
    int coordinateX2;
    int coordinateY2;
    int coordinateX3;
    int coordinateY3;
    int coordinateX4;
    int coordinateY4;


};

#endif // PADDLE_H
