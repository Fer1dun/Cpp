#ifndef BULDOZER_H
#define BULDOZER_H
#include <string>
#include "robot.h"

class Map;

class buldozer : public robot {
    friend class Map;
public:
    buldozer();
    buldozer(Map* map, int x, int y);
    buldozer(std::string newType, int newStrength, int newHit, std::string name);
    std::string getType();
};

#endif