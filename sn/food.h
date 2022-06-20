#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdlib>
#define width 30
#define height 20
class food {
	private:
		COORD pos;
	public:
		void gen_food();
		COORD get_food_pos();
};

#endif