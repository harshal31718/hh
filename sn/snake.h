#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>
#define width 30
#define height 20
using namespace std;
class snake {
	private:
		COORD position; // included in windows.h
		int length;
		int velocity;
		char direction;
		vector <COORD> body;
	public:
		snake(COORD pos,int vel);
//		void set_vel(int v);
		void set_dir(char dir);
		void move_snake();
		COORD get_pos();
		int get_len();
		vector<COORD> get_body();
		bool food_eaten(COORD f);
		void grow();
		bool N_coll();
};

#endif