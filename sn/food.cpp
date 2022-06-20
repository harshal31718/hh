#include "food.h"

void food::gen_food() {
	pos.X=(rand()%(width-1))+1;
	pos.Y=(rand()%(height-1))+1;
}
COORD food::get_food_pos() {
	return pos;
}
