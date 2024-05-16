#ifndef HUMANIC_H
#define HUMANIC_H
#include <string>
#include "robot.h"
class Map;

class humanic:public robot{
	friend class Map;
public:
	humanic();
	humanic(Map*map,int x,int y);
    humanic(std::string newType, int newStrength, int newHit,std::string name);

};
class optimusprime:public humanic{
	friend class Map;
public:
	optimusprime();
	optimusprime(Map*map,int x,int y);
    optimusprime(std::string newType, int newStrength, int newHit,std::string name);
    std::string getType();

};
class robocop:public humanic{
	friend class Map;
public:
	robocop();
	robocop(Map*map,int x,int y);
    robocop(std::string newType, int newStrength, int newHit,std::string name);
    std::string getType();
};
#endif