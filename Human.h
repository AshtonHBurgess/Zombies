//
// Created by asbur on 12/5/2022.
//

#ifndef ZOMBIESWITHVECTORS2_HUMAN_H
#define ZOMBIESWITHVECTORS2_HUMAN_H



#include "Organism.h"
#include "City.h"
class Human : public Organism
{
public:
    Human();
    Human( City *city, int x, int y );
    void spawn();
    void move();
    int getSpecies();
    bool starve();
    bool validMove(int xPos, int yPos);
    void eat();

private:

};
#endif //ZOMBIESWITHVECTORS2_HUMAN_H
