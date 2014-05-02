#include "brick.h"




Brick::Brick(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4) :

  coordinateX1(x1),
  coordinateY1(y1),
  coordinateX2(x2),
  coordinateY2(y2),
  coordinateX3(x3),
  coordinateY3(y3),
  coordinateX4(x4),
  coordinateY4(y4) {

  hitpoints = 1;
}

Brick::Brick(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4, int hp) :

  coordinateX1(x1),
  coordinateY1(y1),
  coordinateX2(x2),
  coordinateY2(y2),
  coordinateX3(x3),
  coordinateY3(y3),
  coordinateX4(x4),
  coordinateY4(y4),
  hitpoints(hp)  {}



void Brick::render(QPainter &painter)
{

    if (isDone())  return;

    QPolygon polygon;
        polygon << QPoint(coordinateX1, coordinateY1) << QPoint(coordinateX2, coordinateY2)
                 << QPoint(coordinateX3, coordinateY3) << QPoint(coordinateX4, coordinateY4);


    painter.setPen ( Qt::black );
    if (hitpoints % 2 == 0) {
        painter.setBrush( QBrush( Qt::black ) );
    } else  {
        painter.setBrush(QBrush( Qt::red ));
    }
    painter.drawPolygon(polygon);

}


bool Brick::isDone() {
    return hitpoints == 0;
}

int Brick::getX1Coordinate() {
    return coordinateX1;
}
int Brick::getX2Coordinate() {
    return coordinateX2;
}
int Brick::getX3Coordinate() {
    return coordinateX3;
}
int Brick::getX4Coordinate() {
    return coordinateX4;
}
int Brick::getY1Coordinate() {
    return coordinateY1;
}
int Brick::getY2Coordinate() {
    return coordinateY2;
}
int Brick::getY3Coordinate() {
    return coordinateY3;
}

int Brick::getY4Coordinate() {
    return coordinateY4;
}

int Brick::getHitpoints() {
    return hitpoints;
}

void Brick::decrementHitpoints() {
    hitpoints--;
}

Brick::~Brick(){

}
