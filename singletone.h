#ifndef SINGLETON_H
#define SINGLETON_H
#include "coordinate.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
class Singleton
{
public:
    static Singleton* Instance();
    static bool loadConfigurationFile();
    //static bool saveConfigurationFile();
    static Coordinate getBallCoordinate();
    static unsigned int getBallXSpeed();
    static unsigned int getBallYSpeed();
    static unsigned int getBallType();
    static unsigned int getBallRadius();
    static unsigned int getBoxHeight();
    static unsigned int getBoxWidth();
protected:
    Singleton();
private:
    static Singleton* m_instance;
    static unsigned int  m_boxHeight;
    static unsigned int  m_boxWidth;
    static unsigned int  m_ballRadius;
    static unsigned int  m_ballPositionX;
    static unsigned int  m_ballPositionY;
    static unsigned int  m_ballSpeedX;
    static unsigned int  m_ballSpeedY;
    static unsigned int  m_ballType;
};

#endif // SINGLETON_H
