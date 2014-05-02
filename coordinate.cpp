#include "coordinate.h"
#include <QDebug>

Coordinate:: Coordinate(unsigned int xCoordinate, unsigned int yCoordinate, unsigned int frameHeight, unsigned int frameWidth):
    m_xCoordinate(xCoordinate), m_yCoordinate(yCoordinate), m_frameHeight(frameHeight), m_frameWidth(frameWidth)
{

}

int Coordinate::getQtRenderingYCoordinate()
{
    return m_frameHeight - m_yCoordinate;
}

int Coordinate::getQtRenderingXCoordinate(){

    return m_xCoordinate;
}

void Coordinate::changeInXCoordinate(int change){
    m_xCoordinate += change;
}

void Coordinate::changeInYCoordinate(int change) {
    m_yCoordinate += change;
}

void Coordinate::setYCoordinateToZero(int offset){
    m_yCoordinate = offset;
}
void Coordinate::setXCoordinateToZero(int offset){
    m_xCoordinate = offset;
}

void Coordinate::setYCoordinate(int value){
    m_yCoordinate = value;
}

void Coordinate::setXCoordinate(int value){
    m_xCoordinate = value;
}

unsigned int Coordinate::getFrameHeight(){
    return m_frameHeight;
}

unsigned int Coordinate::getFrameWidth(){
    return m_frameWidth;
}
