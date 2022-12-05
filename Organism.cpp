//
// Created by asbur on 11/29/2022.
//
#include "Organism.h"

Organism::Organism() {

    city = NULL;
    moved = false;
    hasEaten = false;
    breedTicks = 0;
    x=0;
    y=0;
}

Organism::Organism(City *city, int x, int y) {
    this->city = city;
    moved = false;
    hasEaten = false;
    breedTicks = 0;
    this->x=x;
    this->y=y;
    city->setOrganism(this,x,y);
}

Organism::~Organism() {

}

//bool Organism::validMove(int xPos, int yPos) {
//
//    if((xPos>=0 && xPos<GRIDSIZE && yPos>=0 && yPos<GRIDSIZE)&& (city->grid[xPos][yPos] == NULL))
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
