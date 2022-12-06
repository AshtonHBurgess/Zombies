//
// Created by asbur on 11/29/2022.
//
#include "Organism.h"




Organism::Organism() {

    city = nullptr;
    breedTicks = 0;
    starveCount=0;
    x=0;
    y=0;

}

Organism::Organism(City *city, int x, int y) {
    this->city = city;
    breedTicks = 0;
    this->x=x;
    this->y=y;
//    starveCount=0;
    city->setOrganism(this,x,y);
}

Organism::~Organism() {

}



