#include "configurationmanager.h"
#include <QDebug>

//Singleton class responsible for managing the game's settings.

ConfigurationManager* ConfigurationManager::m_instance = 0;

unsigned int  ConfigurationManager::m_boxHeight = 0;
unsigned int  ConfigurationManager::m_boxWidth = 0;
unsigned int  ConfigurationManager::m_ballRadius = 0;
unsigned int  ConfigurationManager::m_ballPositionX = 0;
unsigned int  ConfigurationManager::m_ballPositionY = 0;
double ConfigurationManager::m_ballSpeedX= 0.0;
double ConfigurationManager::m_ballSpeedY=0.0;
unsigned int  ConfigurationManager::m_ballType=0;

ConfigurationManager::ConfigurationManager(){

}

ConfigurationManager* ConfigurationManager::Instance(){
    if(!m_instance==0){
        m_instance = new ConfigurationManager();
    }
    return m_instance;
}



bool ConfigurationManager::loadConfigurationFile()
{

    resetConfiguration();
    std::string line;
    //std::ifstream myfile ("/Users/yermek/Downloads/A2/settings.config");
    std::ifstream myfile ("/Users/yermek/Desktop/AssignmentTwoBaseSeven/NewBouncingBall/settings.config");
    if (myfile.is_open())
    {
        //loop around of the config file lines to get the parameters
        while ( getline (myfile,line) )
        {
            //title
            if(line.compare(std::string("BOUNCING_BALL_CONFIGS"))==0){
                continue;
            }

            //box dimensions
            if(line.compare(0,14, std::string("BOX_DIMENSIONS"))==0){
                std::istringstream iss(line.substr(14));
                if ( iss >> m_boxWidth >> m_boxHeight ) {
                    continue;
                } else {
                    qDebug("Error reading the BOX_DIMENSIONS parameter");
                    return false;
                }
            }
            //ball dimensions
            if(line.compare(0,14, std::string("BALL_DIMENSION"))==0){
                std::istringstream iss(line.substr(14));

                if ((iss >> m_ballRadius)){
                    continue;
                } else {
                    qDebug("Error reading the BALL_DIMENSION parameter");
                    return false;
                }
            }

            //ball position
            if(line.compare(0,13, std::string("BALL_POSITION"))==0){
                std::istringstream iss(line.substr(13));

                if ((iss >> m_ballPositionX >> m_ballPositionY)){
                    continue;
                }else{
                    qDebug("Error reading the BALL_POSITION parameter");
                    return false;
                }
            }


            //ball speed
            if(line.compare(0,14, std::string("BALL_X_Y_SPEED"))==0){
                std::istringstream iss(line.substr(14));

                if ((iss >> m_ballSpeedX >> m_ballSpeedY)){
                    continue;
                }else{
                    qDebug("Error reading the BALL_X_Y_SPEED parameter");
                    return false;
                }
            }

            //ball type (utility to be implemented)
            if(line.compare(0,9, std::string("BALL_TYPE"))==0){
                std::istringstream iss(line.substr(9));

                if ((iss  >> m_ballType)){
                    continue;
                }
                else{
                    qDebug("Error reading the BALL_TYPE parameter");
                    return false;
                }
            }
        }
        myfile.close();

    }else{
        qDebug("Couldn't open the file.");
        return false;
    }

    //verify if all the fields were read by the config manager
    if(  m_boxHeight == 0 ||
         m_boxWidth == 0 ||
         m_ballRadius == 0 ||
         m_ballPositionX == 0 ||
         m_ballPositionY == 0 ||
         m_ballSpeedX == 0.0 ||
         m_ballSpeedY == 0.0 ||
         m_ballType == 0) {
        qDebug("Did not found all parameters. Verify your settings.config file.");
        return false;
    }
    return true;
}


Coordinate ConfigurationManager::getBallCoordinate()
{
    return Coordinate(m_ballPositionX, m_ballPositionY, m_boxHeight, m_boxWidth);
}

double ConfigurationManager::getBallXSpeed()
{
    return m_ballSpeedX;
}

double ConfigurationManager::getBallYSpeed()
{
    return m_ballSpeedX;
}

unsigned int ConfigurationManager::getBoxHeight()
{
    return m_boxHeight;
}

unsigned int ConfigurationManager::getBoxWidth()
{
    return m_boxWidth;
}

unsigned int ConfigurationManager::getBallType()
{
    return m_ballType;
}

unsigned int ConfigurationManager::getBallRadius()
{
    return m_ballRadius;
}

void ConfigurationManager::resetConfiguration(){
    m_boxHeight = 0;
    m_boxWidth = 0;
    m_ballRadius = 0;
    m_ballPositionX = 0;
    m_ballPositionY = 0;
    m_ballSpeedX = 0.0;
    m_ballSpeedY = 0.0;
    m_ballType = 0;
}
