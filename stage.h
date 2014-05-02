#ifndef STAGE_H
#define STAGE_H
#include <QPainter>
//todo: implement the area of the game
class Stage
{
public:
    Stage(unsigned int width, unsigned int height);
    ~Stage();
    void render(QPainter &painter, unsigned int time);
private:
   unsigned int m_width;
   unsigned int m_height;
};

#endif // STAGE_H



