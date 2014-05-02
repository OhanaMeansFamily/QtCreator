#include "paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4) :

  coordinateX1(x1),
  coordinateY1(y1),
  coordinateX2(x2),
  coordinateY2(y2),
  coordinateX3(x3),
  coordinateY3(y3),
  coordinateX4(x4),
  coordinateY4(y4) {}



void Paddle::render(QPainter &painter, Paddle *p, int pressed) {

    int shift = 0;
    QPolygon polygon;
        polygon << QPoint(coordinateX1, coordinateY1) << QPoint(coordinateX2 + shift, coordinateY2)
                 << QPoint(coordinateX3 + shift, coordinateY3) << QPoint(coordinateX4, coordinateY4);

    painter.setPen ( Qt::black );
    painter.setBrush(QBrush( Qt::gray ));
    painter.drawPolygon(polygon);
    if (pressed == 1)
    p->changeX(20);
    else if (pressed == 2) p->changeX(-20);

}

void Paddle::changeX(int change) {

      if (coordinateX1 + change < 0) {
        coordinateX3 = coordinateX3 - coordinateX1;
        coordinateX2 = coordinateX2 - coordinateX1;
        coordinateX1 = 0;
        coordinateX4 = 0;

      }
      else if (coordinateX2 + change >= ConfigurationManager::Instance()->getBoxWidth()) {
        coordinateX1 = coordinateX1 + ConfigurationManager::Instance()->getBoxWidth() - coordinateX3;
        coordinateX4 = coordinateX4 + ConfigurationManager::Instance()->getBoxWidth() - coordinateX3;
        coordinateX2 = ConfigurationManager::Instance()->getBoxWidth();
        coordinateX3 = ConfigurationManager::Instance()->getBoxWidth();
      } else {
          coordinateX2 = coordinateX2 + change;
          coordinateX3 = coordinateX3 + change;
          coordinateX1 = coordinateX1 + change;
          coordinateX4 = coordinateX4 + change;
      }
}


int Paddle::getX1Coordinate() {
    return coordinateX1;
}
int Paddle::getX2Coordinate() {
    return coordinateX2;
}
int Paddle::getX3Coordinate() {
    return coordinateX3;
}
int Paddle::getX4Coordinate() {
    return coordinateX4;
}
int Paddle::getY1Coordinate() {
    return coordinateY1;
}
int Paddle::getY2Coordinate() {
    return coordinateY2;
}
int Paddle::getY3Coordinate() {
    return coordinateY3;
}

int Paddle::getY4Coordinate() {
    return coordinateY4;
}
