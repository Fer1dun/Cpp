#include <iostream>
#include <string>
#include "humanic.h"
humanic::humanic() : robot() {}

humanic::humanic(std::string newType, int newStrength, int newHit,std::string name) : robot(newType, newStrength, newHit, name) {}

humanic::humanic(Map*map,int x,int y):robot(map,x,y){}

robocop::robocop() : humanic(){
	newType="robocop";
		newStrength=30;
		newHit=40;
}

robocop::robocop(Map*map,int x,int y) : humanic(map,x,y) {
		newType="robocop";
		newStrength=30;
		newHit=40;
        static int count = 0;
        setName("robocop_" + std::to_string(count));
        count++;
    }

robocop::robocop(std::string newType, int newStrength, int newHit,std::string name) : humanic(newType, newStrength, newHit, name) {}

std::string robocop::getType(){
return "robocop";
}
optimusprime::optimusprime():humanic(){
	newType="optimusprime";
	newStrength=100;
	newHit=100;
}

optimusprime::optimusprime(Map*map,int x,int y) : humanic(map,x,y) {
	newType="optimusprime";
	newStrength=100;
	newHit=100;
        static int count = 0;
        setName("optimusprime_" + std::to_string(count));
        count++;
    }

optimusprime::optimusprime(std::string newType, int newStrength, int newHit,std::string name) : humanic(newType, newStrength, newHit, name) {}

std::string optimusprime::getType(){
return "optimusprime";
}