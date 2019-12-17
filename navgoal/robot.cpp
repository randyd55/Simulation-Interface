#include "robot.h"

Robot::Robot(float xPos, float yPos, float zPos, float xOrient, float yOrient, float zOrient, float wOrient)
{
    this->xPos = xPos;
    this->yPos = yPos;
    this->zPos = zPos;
    this->xOrient = xOrient;
    this->yOrient = yOrient;
    this->zOrient = zOrient;
    this->wOrient = wOrient;
}
