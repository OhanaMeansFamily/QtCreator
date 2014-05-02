#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdlib.h>

class Coordinate
{
public:
    Coordinate(unsigned int xCoordinate, unsigned int yCoordinate, unsigned int frameHeight, unsigned int frameWidth);

    int getQtRenderingXCoordinate();
    int getQtRenderingYCoordinate();

    void changeInXCoordinate(int change);
    void changeInYCoordinate(int change);

    void setYCoordinateToZero(int offset);
    void setXCoordinateToZero(int offset);

    void setYCoordinate(int value);
    void setXCoordinate(int value);

    unsigned int getFrameHeight();
    unsigned int getFrameWidth();

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_frameHeight;
    unsigned int m_frameWidth;

};

#endif // COORDINATE_H
