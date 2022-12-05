#ifndef _GAMESPECS_H
#define _GAMESPECS_H




//stores ONLY global consts

const int GRIDSIZE = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 100; // inital Humans
const int ZOMBIE_STARTCOUNT =100; //initial Zombie count
const int HUMAN_BREED = 3; // steps until an Human breeds
const int ZOMBIE_BREED = 8; // steps until an Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const char HUMAN_CH = 'h';
const char ZOMBIE_CH = 'z';

const double PAUSE_SECONDS = .5; // pause between steps
const int ITERATIONS = 1000 ;// max number of steps

//    system("color 3f");

//Colors
//0  = black				//9  = bright blue
//1  = blue					//10 = bright green
//2  = green				//11 = bright turquoise
//3  = turquise				//12 = bright red
//4  = red					//13 = bright pink
//5  = pink					//14 = bright yellow
//6  = yellow				//15 = bright white
//7  = white regular		//16+ = solid blocks
//8  = white pale

const int HUMAN_COLOR = 3; // turquoise
const int ZOMBIE_COLOR = 14; // bright yellow
const char STANDARD_COLOR = 7;//90








#endif