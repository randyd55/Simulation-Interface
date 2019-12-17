#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
public:
    Robot(float xPos, float yPos, float zPos, float xOrient, float yOrient, float zOrient, float wOrient);
    float xPos;
    float yPos;
    float zPos;
    float xOrient;
    float yOrient;
    float zOrient;
    float wOrient;
};

#endif // ROBOT_H
