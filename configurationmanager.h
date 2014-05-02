#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H
#include "coordinate.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
class ConfigurationManager
{
public:
    static ConfigurationManager* Instance();
    static bool loadConfigurationFile();
    //static bool saveConfigurationFile();
    static Coordinate getBallCoordinate();
    static double getBallXSpeed();
    static double getBallYSpeed();
    static unsigned int getBallType();
    static unsigned int getBallRadius();
    static unsigned int getBoxHeight();
    static unsigned int getBoxWidth();
protected:
    ConfigurationManager();
private:
    static void resetConfiguration();
    static ConfigurationManager* m_instance;
    static unsigned int  m_boxHeight;
    static unsigned int  m_boxWidth;
    static unsigned int  m_ballRadius;
    static unsigned int  m_ballPositionX;
    static unsigned int  m_ballPositionY;
    static double  m_ballSpeedX;
    static double  m_ballSpeedY;
    static unsigned int  m_ballType;
    static unsigned int m_number_of_bricks;
};



#endif // CONFIGURATIONMANAGER_H
