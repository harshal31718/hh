#include <iostream>
#include "snake.h"
#include "food.h"
// #include <cstdlib>  // to clear console
// #include <windows.h>  // to control cursors position || used in snake.h
#include <conio.h>  // console ip op to capture keystorkes
#include <time.h>

using namespace std;

#define width 30
#define height 20
snake sn({3,3},1);
food fd;
void board() {
	COORD sn_pos=sn.get_pos();
	COORD fd_pos=fd.get_food_pos();
	vector<COORD> snake_body=sn.get_body();
	for(int i=0; i<height; i++) {
		cout<<"\t\t\t\t";
		for(int j=0; j<width; j++) {
			if(i==0 || i==height-1 || j==width-1 || j==0) cout<<" #";
			else if(i==sn_pos.Y && j==sn_pos.X) cout<<" 0";
			else if(i==fd_pos.Y && j==fd_pos.X) cout<<" @";
			else {
				bool isBodyPart=false;
				for(int k=0; k<snake_body.size()-1; k++) {
					if(i==snake_body[k].Y && j==snake_body[k].X) {
						cout<<" o";
						isBodyPart=true;
						break;
					}
				}
				if(!isBodyPart) cout<<"  ";
			}
		}
		cout<<endl;
	}
}
int main() {
	srand(time(NULL));

	fd.gen_food();
	while(1) {
		board();
		if(kbhit()) {
			switch(getch()) {
				case 'w':
					sn.set_dir('w');
					break;
				case 'd':
					sn.set_dir('d');
					break;
				case 'a':
					sn.set_dir('a');
					break;
				case 's':
					sn.set_dir('s');
					break;
			}
		}
		if(sn.food_eaten(fd.get_food_pos())) {
			fd.gen_food();
			sn.grow();
		}
		if(sn.N_coll())
			break;
		sn.move_snake();
// system("cls"); // clears and rewrites
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
	}
	cout<<"\t\t\t\t\t\t\t\t\tGAME OVER\n\t\t\t\t\t\t\t\t\tScore: "<<sn.get_len()<<endl;

	return 0;
}