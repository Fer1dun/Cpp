#ifndef ROBOT_H
#define ROBOT_H
#include <string>
const int grid_size=10;
class robot;
class buldozer;
class roomba;
class Map{
	public:
		friend class robot;
		friend class buldozer;
		friend class roomba;
		Map();
		~Map();
		robot* getAt(int x,int y);
		void set_At(int x,int y,robot *rob);
		void display();
		void step();
	private:
		robot* grid[grid_size][grid_size];
};
class robot{
	friend class Map;
	protected:
		std::string newType;
		int newStrength;
		int newHit;
		std::string name;
		int x,y;
        bool moved;
        bool dead;
        Map*map;

	public:
		void takeDamage(int damage);
		robot();
		robot(std::string newType,int newStrength,int newHit,std::string name);
		robot(Map*mp,int x,int y);
		int get_strenght();
		void set_strength(int strenght);
		int get_hit();
		void move();
		int get_x();
		int get_y();
		bool isDead();
		void set_hit(int hit);
		void setName(std::string name);
		std::string getName();
		virtual std::string getType()=0;
		int getDamage();


};

#endif