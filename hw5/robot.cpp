#include <iostream>
#include <string>
#include "robot.h"
//fills the map as null
Map::Map(){
	for(int i=0;i<grid_size;i++){
		for(int j=0;j<grid_size;j++){
			grid[i][j]=NULL;
		}
	}
}
Map::~Map(){
	for(int i=0;i<grid_size;i++){
		for(int j=0;j<grid_size;j++){
			if(grid[i][j]!=NULL) delete(grid[i][j]);
		}
	}

}
robot*Map::getAt(int x,int y){
	if((x>=0) && (x<grid_size) && (y>=0) && (y<grid_size)) return grid[x][y];
    return NULL;

}
void Map::set_At(int x,int y,robot*rob){
	if((x>=0) && (x<grid_size) && (y>=0) && (y<grid_size)) grid[x][y]=rob;
  
}
//its write a map 
void Map::display(){
	for(int i=0;i<grid_size;i++){
		for(int j=0;j<grid_size;j++){
			if(grid[i][j]==NULL) std::cerr<<".";
			else if(grid[i][j]->getType()=="roomba") std::cout<<"R";
			else if(grid[i][j]->getType()=="buldozer") std::cout<<"B";
			else if(grid[i][j]->getType()=="humanic") std::cout<<"H";
			else if(grid[i][j]->getType()=="optimusprime") std::cout<<"O";
			else if(grid[i][j]->getType()=="robocop") std::cout<<"r";
			
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
void robot::setName(std::string name){
	this->name=name;

}
std::string robot::getName(){
	return name;
}
robot::robot(){
	x=0;
	y=0;
	moved=false;
	name="";
	map=NULL;
}
robot::robot(Map*mp,int x,int y){
	this->map=mp;
	this->x=x;
	this->y=y;
	mp->set_At(x, y, this);
}
robot::robot(std::string newType,int newStrength,int newHit,std::string name){
	this->newHit=newHit;
	this->name=name;
	this->newStrength=newStrength;
	this->newType=newType;
}
bool robot::isDead() {
    if(newHit<=0)
    	return true;
    else return false;
}
int robot::get_x() {
  return x;
}

int robot::get_y() {
  return y;
}
void Map::step() {
    int robot_count = 20;
    int moved_robots = 0;
    int robots_alive = robot_count;
    
    while (robots_alive > 1) {
        moved_robots = 0;
        
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                robot* curr_robot = grid[i][j];
                if (curr_robot != NULL && !curr_robot->moved) {
                    curr_robot->moved = true;
                    curr_robot->move();
                    moved_robots++;
					// Check if there is a robot to the right
            if (j+1 < grid_size && grid[i][j+1] != NULL) {
                // Fight!
                grid[i][j+1]->takeDamage(grid[i][j+1]->getDamage());
                curr_robot->takeDamage(curr_robot->getDamage());
                std::cout << curr_robot->getName() << "(" << curr_robot->newStrength << ") atacaks" << grid[i][j+1]->getName() << "(" << grid[i][j+1]->newStrength << ")" << std::endl;
            }
           
                    // Check if a robot died
                    
                    if (curr_robot->isDead()) {
                        curr_robot->map->set_At(curr_robot->x, curr_robot->y, NULL);
                        robots_alive--;
                    }
          
                }
            }
        }
        display();
        // Reset moved flags
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                robot* curr_robot = grid[i][j];
                if (curr_robot != NULL) {
                    curr_robot->moved = false;
                }
            }
        }
    }
    
    // Find the last robot standing
    robot* last_robot = NULL;
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            robot* curr_robot = grid[i][j];
            if (curr_robot != NULL && !curr_robot->isDead()) {
                last_robot = curr_robot;
            }
        }
    }
    
    // Print the winner
    if (last_robot != NULL) {
        std::cout << "The winner is Robot #" << last_robot->getName() << "!" << std::endl;
    } else {
        std::cout << "No robot survived the battle." << std::endl;
    }
}

	

void robot::move() {
  
    
    // Move to empty space to the down
    if (x < grid_size && map->getAt(x-1, y) == NULL) {
    // Move to empty space below
    map->set_At(x-1, y, this);
    map->set_At(x, y, NULL);
    x--;
  
}
// Move to empty space to the right
else if (y < grid_size && map->getAt(x, y+1) == NULL) {
    map->set_At(x, y+1, this);
    map->set_At(x, y, NULL);
    y++;
    
}
// Move to empty space above
else if (x > 0 && map->getAt(x+1, y) == NULL) {
   
    map->set_At(x+1, y, this);
    map->set_At(x, y, NULL);
    x++;
    
}
// Move to empty space to the left
else if (y > 0 && map->getAt(x, y-1) == NULL) {
    
    map->set_At(x, y-1, this);
    map->set_At(x, y, NULL);
    y--;
    
}
}


void robot::takeDamage(int damage) {
    newHit=newHit- damage;
    std::cerr<<getName();
    std::cerr<<"healt:"<<newHit<<std::endl;
    if (newHit <= 0) {
        // robot has died, remove it from the map
        map->set_At(x, y, NULL);
        delete this;
    }
}

int robot::getDamage(){
	 int damage = (rand() % newStrength) + 1;

    // Humanic robots have a 10% chance of a tactical nuke attack
    if (getType() == "optimusprime" || getType() == "robocop"|| getType() == "humanic") {
        int tacticalNukeChance = rand() % 10;
        if (tacticalNukeChance == 0) {
            damage += 50;
            std::cout << "Tactical nuke launched for additional 50 damage!" << std::endl;
        }
    }

    // Optimusprime robots have a 15% chance of a strong attack
    if (getType() == "optimusprime") {
        int strongAttackChance = rand() % 100;
        if (strongAttackChance < 15) {
            damage *= 2;
            std::cout << "Optimusprime uses strong attack for double damage!" <<std:: endl;
        }
    }

    // Roomba robots attack twice
    if (getType() == "roomba") {
        int attackCount = 2;
        while (attackCount > 0) {
            int roombaDamage = (rand() % newStrength) + 1;
            std::cout << getName()<<"  " << roombaDamage << " points!" <<std::endl;
            damage += roombaDamage;
            attackCount--;
        }
    }

    return damage;
}