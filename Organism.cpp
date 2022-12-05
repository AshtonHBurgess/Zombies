//
// Created by asbur on 11/29/2022.
//
#include "Organism.h"




Organism::Organism() {

    city = NULL;
    moved = false;
    hasEaten = false;
    breedTicks = 0;
    starvation=0;
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
    starvation=0;
    city->setOrganism(this,x,y);
}

Organism::~Organism() {

}
