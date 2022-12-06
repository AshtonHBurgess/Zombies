//
// Created by asbur on 12/5/2022.
//

#ifndef ZOMBIESWITHVECTORS2_ZOMBIE_H
#define ZOMBIESWITHVECTORS2_ZOMBIE_H



#include "Organism.h"
#include "City.h"

class Zombie : public Organism
{
public:
    Zombie();
    Zombie( City *city, int x, int y );
    virtual ~Zombie();
    void spawn();
    void move();
    void eat();
    int getSpecies();
    bool starve();
    bool validMove(int cordinateX, int cordinateY) ;
    bool validEat(int cordinateX, int cordinateY) ;
};

#endif //ZOMBIESWITHVECTORS2_ZOMBIE_H
