#include <iostream>
#include <string>
#include <random>
#include "robot.h"
#include "buldozer.h"
#include "humanic.h"
#include "roomba.h"
int main(){
    srand(time(NULL));
	Map all_robot;
	int buldozer_count=0;
    while(buldozer_count < 5){
        int x = rand() % grid_size;
        int y = rand() % grid_size;
        if(all_robot.getAt(x, y) == NULL){
            buldozer_count++;
            robot* a1 = new buldozer(&all_robot, x, y);
        }
    }
    int optimus=0;
    while(optimus < 5){
        int x = rand() % grid_size;
        int y = rand() % grid_size;
        if(all_robot.getAt(x, y) == NULL){
            optimus++;
            robot* x1 = new optimusprime(&all_robot, x, y);
        }
    }
    int rob=0;
    while(rob < 5){
        int x = rand() % grid_size;
        int y = rand() % grid_size;
        if(all_robot.getAt(x, y) == NULL){
            rob++;
            robot* k1 = new robocop(&all_robot, x, y);
        }
    }
    int room=0;
    while(room< 5){
        int x = rand() % grid_size;
        int y = rand() % grid_size;
        if(all_robot.getAt(x, y) == NULL){
            room++;
            robot* t1 = new roomba(&all_robot, x, y);
        }
    }
    	all_robot.display();
    	all_robot.step();
        
    
return 0;
}


