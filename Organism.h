//
// Created by asbur on 12/5/2022.
//

#ifndef ZOMBIESWITHVECTORS2_ORGANISM_H
#define ZOMBIESWITHVECTORS2_ORGANISM_H


#include <iostream>
#include "GameSpecs.h"
#include "City.h"


#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class City;

class Organism
{

    friend class City;
protected:
    int x;
    int y;
    bool moved;
    bool hasEaten;
    int breedTicks;
    City *city;
    int starvation;

public:
    Organism();
    Organism( City *city, int x, int y );
    virtual ~Organism();
    virtual void spawn() = 0;
    virtual void move() = 0;
    virtual bool validMove(int cordinateX, int cordinateY) =0;
    virtual int getSpecies() = 0;
    virtual void starve() = 0;
    virtual void eat() = 0;
    virtual bool validEat(int cordinateX, int cordinateY) =0;
    enum direction_NUM{NW,N,NE,E,SE,S,SW,W};

//	virtual Organism* getPosition(int x, int y) = 0;
//    virtual bool canMove(int x, int y) = 0;
//	void setPosition( int x, int y,Organism* newOrganism );
//	void endTurn();
//	bool isTurn();

//	friend ostream& operator<<( ostream &output, Organism *organism );

//    void moveTo(int x, int y);



};

#endif //ZOMBIESWITHVECTORS2_ORGANISM_H
