#ifndef _GAMESPECS_H
#define _GAMESPECS_H
const int GRIDSIZE = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 0 ;// inital Humans   100
const int ZOMBIE_STARTCOUNT = 1; //initial Zombie count  5
const int HUMAN_BREED = 3; // steps until an Human breeds
const int ZOMBIE_BREED = 8; // steps until an Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const char HUMAN_CH = 111;//79 "o"// ascii Human
const char SPACE_CH = 32; // " " ascii space
const char ZOMBIE_CH = 90;//90 "Z"// ascii zombie
const double PAUSE_SECONDS = 2000; // pause between steps
const int ITERATIONS = 1000; // max number of steps
const int HUMAN_COLOR = 3; // turquoise
const int ZOMBIE_COLOR = 14; // bright yellow
const char STANDARD_COLOR = 7;//90
#endif