#ifndef BRICK_H
#define BRICK_H

#include "coordinate.h"
#include "brick.h"
#include <QPainter>

class Brick
{
public:
    Brick();
    Brick(Coordinate coordinate);
    Brick(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    Brick(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4, int hp);

    bool isDone();
    void render(QPainter &painter);
    int getX1Coordinate();
    int getX2Coordinate();
    int getY1Coordinate();
    int getY2Coordinate();

    int getX3Coordinate();
    int getX4Coordinate();
    int getY3Coordinate();
    int getY4Coordinate();

    int getHitpoints();

    void decrementHitpoints();

 ~Brick();
private:

   int width;
   int height;
   int coordinateX1;
   int coordinateY1;
   int coordinateX2;
   int coordinateY2;
   int coordinateX3;
   int coordinateY3;
   int coordinateX4;
   int coordinateY4;
   int hitpoints;

};

#endif // BRICK_H
