#include <iostream>
#include <string>
#include "buldozer.h"
buldozer::buldozer():robot(){
	newType="buldozer";
		newHit=200;
		newStrength=50;
}
buldozer::buldozer(Map*map,int x,int y) : robot(map,x,y) {
		newType="buldozer";
		newHit=200;
		newStrength=50;
        static int count = 0;
        setName("buldozer_" + std::to_string(count));
        count++;
    }
buldozer::buldozer(std::string newType, int newStrength, int newHit,std::string name) : robot(newType, newStrength, newHit, name) {}

std::string buldozer::getType(){
return "buldozer";
}
