//
// Created by asbur on 12/5/2022.
//

#ifndef ZOMBIESWITHVECTORS2_CITY_H
#define ZOMBIESWITHVECTORS2_CITY_H


#include <iostream>
#include "Organism.h"
#include "GameSpecs.h"



class Organism;
class City
{
public:
    City();
    ~City();
//    virtual ~City();
    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );
    void setNewOrganism( Organism *organism, int x, int y );
//    friend ostream& operator<<( ostream &output, City &city );
    void printGrid( City &city );
    void move();
    int countType(int type);
    bool hasDiversity();//Ashton Added    randomize
    int getRandNumBetween(int startRange, int endRange) ;

    int  getEaten();
    int  getRecruited();
    int  getCured();
    int  getConverted();
    int  getGeneration();

    //Can either use protected with friend class members,
    //   private with getters and setters
    //       or make public
    friend class Human;
    friend class Organism;
    friend class Zombie;
public:
    Organism *grid[GRIDSIZE][GRIDSIZE];
    int gen;
    int eaten;
    int recruited;
    int converted;
    int cured;
};


#endif //ZOMBIESWITHVECTORS2_CITY_H
