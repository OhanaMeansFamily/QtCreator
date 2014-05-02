#include "stage.h"
//todo: implement game area
Stage::Stage(unsigned int width, unsigned int height):m_width(width), m_height(height)
{

}

void Stage::render(QPainter &painter, unsigned int time){

    painter.setBrush( QBrush( Qt::red ) );
    painter.drawRect(0,0,this->m_height,this->m_width);
}
