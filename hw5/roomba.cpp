#include <iostream>
#include <string>
#include "roomba.h"
roomba::roomba() :robot(){}
roomba::roomba(Map*map,int x,int y) : robot(map,x,y) {
		newType="roomba";
		newStrength=3;
		newHit=10;
        static int count = 0;
        setName("roomba_" + std::to_string(count));
        count++;
    }

 roomba::roomba(std::string newType, int newStrength, int newHit,std:: string name) : robot(newType, newStrength, newHit, name) {}

std::string roomba::getType(){
return "roomba";
}