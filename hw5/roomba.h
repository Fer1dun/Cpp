#ifndef ROOMBA_H
#define ROOMBA_H
#include <string>
#include "robot.h"
class Map;
class roomba:public robot{
	friend class Map;
public:
    roomba();
    roomba(Map*map,int x,int y);
    roomba(std::string newType, int newStrength, int newHit,std::string name);
    std::string getType();
};

#endif
