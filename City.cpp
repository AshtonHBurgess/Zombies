

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
        organism->starvation=0;
        organism->moved=false;
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
                grid[i][j]->moved = false;
                grid[i][j]->hasEaten = false;
            }
        }
    }


    // MOVE
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==1))//HUMANS
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




    //
//////    //SPAWN ZOMBIES
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
////    //EAT
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




// MOVE ZOMBIES
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
//            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==1))//HUMANS
//            {
//                    grid[i][j]->move();
//
//            }
            if ((grid[i][j]!=NULL) && (grid[i][j]->getSpecies()==2)  && (grid[i][j]->moved== false))//ZOMBIES
            {
                grid[i][j]->move();
            }
        }
    }





////STARVE
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {


                if(grid[i][j]!=NULL && grid[i][j]->starvation >=3)
                {
                     grid[i][j]->starve();

//                    cured++;
//                    grid[i][j] = new Human(this, i, j);


                }
                //spawn new human inplace of zombie


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
                cout << "-";
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
    }
    SetConsoleTextAttribute( h, STANDARD_COLOR );



    //RESET
    for (int i=0; i<GRIDSIZE; i++)
    {
        for (int j=0; j<GRIDSIZE; j++)
        {
            if (grid[i][j]!=NULL)
            {
                grid[i][j]->moved=false;
                grid[i][j]->hasEaten=false;

            }
        }
    }
}




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

    }
    return (hasHuman&&hasZombie);
}

//int City::getGeneration() {
//    return gen;
//}

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
}

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

