

#include "GameSpecs.h"
#include "Organism.h"
#include "City.h"
#include "Zombie.h"
#include "Human.h"

#include <iostream>
#include <windows.h>



int City::getRandNumBetween(int start, int end)  {
    return rand() % (end - start + 1) + start;
}





City::City() {
//MAKE Map


    srand(time(NULL));
//    timeStepCount = 0;
    for (int x = 0; x < GRIDSIZE; x++)
    {
        for (int y = 0; y < GRIDSIZE; y++)
        {
            grid[x][y] = nullptr;
        }
    }
    //ADD ORGANISMS
    int zombieCount = 0;
    int humanCount = 0;
    while (zombieCount < ZOMBIE_STARTCOUNT){
        int a = getRandNumBetween(0, GRIDSIZE - 1);
        int s = getRandNumBetween(0, GRIDSIZE - 1);
        if (grid[a][s] != nullptr) continue;
        grid[a][s] = new Zombie(this, a, s);
        zombieCount++;
    }
    while (humanCount < HUMAN_STARTCOUNT) {
        int a = getRandNumBetween(0, GRIDSIZE - 1);
        int s = getRandNumBetween(0, GRIDSIZE - 1);
        if (grid[a][s] != nullptr) continue;
        grid[a][s] = new Human(this, a, s);
        humanCount++;
    }
cured=0,converted=0, recruited=0, gen=0;
}

City::~City() {
    int i,j;
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if (grid[i][j]!=NULL) delete (grid[i][j]);
        }
    }
}

Organism *City::getOrganism(int x, int y) {
    if ((x>=0) && (x<GRIDSIZE) && (y>=0) && (y<GRIDSIZE))
        return grid[x][y];
    return NULL;
}

void City::setOrganism(Organism *organism, int x, int y) {

    if ((x>=0) && (x<GRIDSIZE) && (y>=0) && (y<GRIDSIZE))
    {
        grid[x][y] = organism;
    }
}

void City::setNewOrganism(Organism *organism, int x, int y) {

    if ((x>=0) && (x<GRIDSIZE) && (y>=0) && (y<GRIDSIZE))
    {

        organism->starveCount=0;
        organism->breedTicks=0;
        grid[x][y] = organism;
    }
}

void City::move() {
    int i,j;
    //reset organisms to not moved
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if (grid[i][j]!=NULL)
            {
            }
        }
    }
//EAT
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {

            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==2))//ZOMBIES
            {
                grid[i][j]->eat();
            }
        }
    }

    // MOVE HUMANS && ZOMBIES
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) )//HUMANS
            {
                grid[i][j]->move();

            }

        }
    }
    //SPAWN HUMANS
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==1))
            {
                grid[i][j]->spawn();
            }

        }
    }
//SPAWN ZOMBIES
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==2))
            {
                grid[i][j]->spawn();
            }

        }
    }
//
//STARVE
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {

            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==2) && grid[i][j]->starveCount >= ZOMBIE_STARVE)
            {
                grid[i][j]->starve();
                cured++;
            }
        }
    }
    this->gen++;
}//END OF CITY MOVE

void City::printGrid( City &city) {
    using namespace std;
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );

    for (int x = 0; x < GRIDSIZE; x++){
        for (int y = 0; y < GRIDSIZE; y++){
            if (city.grid[x][y] == NULL)
                cout << SPACE_CH;
//            output << SPACE_CH;
            else if (city.grid[x][y]->getSpecies() == 1)
            {
                SetConsoleTextAttribute( h, HUMAN_COLOR );
                cout << HUMAN_CH;
                SetConsoleTextAttribute( h, STANDARD_COLOR );
            }
            else  //world[x][y]->getType() == ZOMBIE
            {
                SetConsoleTextAttribute( h, ZOMBIE_COLOR );
                cout << ZOMBIE_CH;
                SetConsoleTextAttribute( h, STANDARD_COLOR );
            }
        }

        cout << endl;
    }//FOR
    SetConsoleTextAttribute( h, STANDARD_COLOR );

    //RESET
//    for (int i=0; i<GRIDSIZE; i++)
//    {
//        for (int j=0; j<GRIDSIZE; j++)
//        {
//            if (grid[i][j]!=NULL)
//            {
//
//            }
//        }//FOR
//    }//FOR
}//END OF PRINT GRID




bool City::hasDiversity() {
    bool hasHuman=false;
    bool hasZombie=false;
    for (int x = 0; x < GRIDSIZE; x++){
        for (int y = 0; y < GRIDSIZE; y++){
            if (grid[x][y] == nullptr)
            {
                //do nothing
            }
            else if (grid[x][y]->getSpecies() == 1)
            {
                hasHuman=true;
            }
            else
            {
                hasZombie=true;
            }
        }

    }//FOR
    return (hasHuman&&hasZombie);
}//END HAS DIVERSITY


int City::countType(int type) {
    int typeCount=0;

    for (int x = 0; x < GRIDSIZE; x++) {
        for (int y = 0; y < GRIDSIZE; y++) {
            if (grid[x][y] == nullptr) {
                //do nothing
            } else if (grid[x][y]->getSpecies() == type) {
                typeCount++;
            }

        }
    }

    return typeCount;
}//END COUNT TYPE

int City::getEaten() {
    return eaten;
}

int City::getRecruited() {
    return recruited;
}

int City::getCured() {
    return cured;
}

int City::getConverted() {
    return converted;
}

int City::getGeneration() {
    return gen;
}

