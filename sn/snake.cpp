#include "snake.h"

snake::snake(COORD pos,int vel) {
	position=pos;
	velocity=vel;
	length=1;
	direction='n';
	body.push_back(position);
}
void snake::set_dir(char dir) {
	if(direction=='n'||((direction=='w'|| direction=='s')&&(dir=='a'||dir=='d')) ||((direction=='a'|| direction=='d')&&(dir=='w'||dir=='s')))
		direction=dir;
}
void snake::move_snake() {
	switch(direction) {
		case 'w':
			position.Y-=velocity;
//			if(position.Y<1)
//				position.Y=height-2-position.Y;
			break;
		case 'd':
			position.X+=velocity;
//			if(position.X>width-2)
//				position.X-=width+2;
			break;
		case 'a':
			position.X-=velocity;
//			if(position.X<1)
//				position.X=width-2-position.X;
			break;
		case 's':
			position.Y+=velocity;
//			if(position.Y>height-2)
//				position.Y-=height+2;
			break;
	}
	body.push_back(position);
	if(body.size()>length) 
		body.erase(body.begin());

}
vector<COORD> snake::get_body() {
	return body;
}
COORD snake::get_pos() {
	return position;
}
int snake::get_len() {
	return length;
}
bool snake::food_eaten(COORD f) {
	if(f.X==position.X && f.Y == position.Y) return 1;
	return 0;
}
void snake::grow() {
	length++;
}
bool snake::N_coll() {
	if(position.X<1 || position.X>(width-2) || position.Y<1 || position.Y>(height-2))
		return 1;
	for(int i=0; i<length-2; i++) {
		if(position.X==body[i].X && position.Y==body[i].Y)
			return 1;
	}
	return 0;
}
