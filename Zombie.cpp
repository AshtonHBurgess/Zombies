//
// Created by asbur on 11/29/2022.
//
#include "Zombie.h"


//Zombie::Zombie() {
//
//    city = NULL;
//    moved = false;
//    hasEaten = false;
//    breedTicks = 0;
//    starvation=0;
//    x=0;
//    y=0;
//
//}
//
//Zombie::Zombie(City *city, int x, int y) {
//    this->city = city;
//    moved = false;
//    hasEaten = false;
//    breedTicks = 0;
//    this->x=x;
//    this->y=y;
//    starvation=0;
//    city->setOrganism(this,x,y);
//}


bool Zombie::validMove(int cordinateX, int cordinateY)  {

    if((cordinateX>=0 && cordinateX<GRIDSIZE && cordinateY>=0 && cordinateY<GRIDSIZE)
    && (city->grid[cordinateX][cordinateY] == NULL))
    {//NULL makes sure there's no organism in that location
        return true;
    }
    else
    {
        return false;
    }
}

bool Zombie::validEat(int cordinateX, int cordinateY) {
    if((cordinateX>=0 && cordinateX<GRIDSIZE && cordinateY>=0 && cordinateY<GRIDSIZE)
       && (city->grid[cordinateX][cordinateY] != NULL) && city->grid[cordinateX][cordinateY]->getSpecies()==1)
    {//NULL makes sure there's no organism in that location
        return true;
    }
    else
    {
        return false;
    }
}






void Zombie::spawn() {
//                enum direction_NUM{N=1, S=2, W=3,E=4,NW=5,NE=6,SE=7,SW=8 };
//
    if  (this->breedTicks >= ZOMBIE_BREED)
    {

        using namespace std;
//    vector<City> moveTargets;
        vector<int> convertTargets ;

        if (validEat(this->x + 1, this->y+1)) {
            convertTargets.push_back(NE);
        }
        if (validEat(this->x , this->y+1)) {
            convertTargets.push_back(N);
        }
        if (validEat(this->x-1, this->y+1)) {
            convertTargets.push_back(NW);
        }
        if (validEat(this->x+1, this->y)) {
            convertTargets.push_back(E);
        }
        if (validEat(this->x+1, this->y-1)) {
            convertTargets.push_back(SW);
        }
        if (validEat(this->x, this->y-1)) {
            convertTargets.push_back(S);
        }
        if (validEat(this->x+1, this->y-1)) {
            convertTargets.push_back(SE);
        }
        if (validEat(this->x-1, this->y)) {
            convertTargets.push_back(W);
        }

//SHUFFLE
        if(!convertTargets.empty()){


            unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
            shuffle(convertTargets.begin(),convertTargets.end(),default_random_engine(seed));

            switch (convertTargets[0]) {
                case N: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x, y + 1);
                        city->converted++;
//



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case S: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x, y - 1);
                    city->converted++;



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case W: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x-1, y);
                    city->converted++;



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case E: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x, y + 1);
                    city->converted++;



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case NW: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x-1, y + 1);
                    city->converted++;



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case NE: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x+1, y + 1);
                    city->converted++;




                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case SW: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x-1, y - 1);
                    city->converted++;



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case SE: {
                    this->breedTicks=0;

                        city->setNewOrganism(this, x+1, y -1);
                    city->converted++;



                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                default:
                    //NO Available Positions
                {
//                    this->breedTicks=0;
                    break;
                }
            }//END OF SWITCH MOVE

        }//IF VECTOR EMPTY
        convertTargets.clear();
    }//IF BREED COUNTER == BREED COUNTER
//    this->breedTicks=0;

}//END OF SPA ZOMBIE











int Zombie::getSpecies() {
    return 2;
}

void Zombie::starve() {
    using namespace std;
    if (this->starvation >= ZOMBIE_STARVE) {
        city->setOrganism(NULL, x, y);
cout<<"starved Zombie"<<endl;

    }
}

void Zombie::move() {
    using namespace std;
//    vector<City> moveTargets;
    vector<int> moveTargets ;

    if (validMove(this->x + 1, this->y+1)) {
        moveTargets.push_back(NE);
    }
    if (validMove(this->x , this->y+1)) {
        moveTargets.push_back(N);
    }
    if (validMove(this->x-1, this->y+1)) {
        moveTargets.push_back(NW);
    }
    if (validMove(this->x+1, this->y)) {
        moveTargets.push_back(E);
    }
    if (validMove(this->x-1, this->y-1)) {
        moveTargets.push_back(SW);
    }
    if (validMove(this->x, this->y-1)) {
        moveTargets.push_back(S);
    }
    if (validMove(this->x+1, this->y-1)) {
        moveTargets.push_back(SE);
    }
    if (validMove(this->x-1, this->y)) {
        moveTargets.push_back(W);
    }
//SHUFFLE


    if(!moveTargets.empty()) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(moveTargets.begin(), moveTargets.end(), default_random_engine(seed));

        switch (moveTargets[0]) {
            case N: {
                if (validMove(this->x, this->y + 1)) {
                    this->breedTicks++;
                    this->starvation++;
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y + 1);
                    this->y += 1;
                    moved = true;

                }
                break;
            }
            case S: {
                if (validMove(this->x, this->y - 1)) {
                    moved = true;
                    this->breedTicks++;
                    this->starvation++;
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y - 1);
                    this->y -= 1;

                }
                break;
            }
            case W: {
                if (validMove(this->x - 1, this->y)) {
                    moved = true;
                    this->breedTicks++;
                    this->starvation++;
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y);
                    this->x -= 1;


                }
                break;
            }
            case E: {
                if (validMove(this->x + 1, this->y)) {
                    moved = true;
                    this->breedTicks++;
                    this->starvation++;
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x + 1, y);
                    this->x += 1;

                }
                break;
            }
        case NW: {
            if (validMove(this->x - 1, this->y + 1)) {
                moved = true;
                this->breedTicks++;
                this->starvation++;
                city->setOrganism(NULL, x, y);
                city->setOrganism(this, x - 1, y + 1);
                this->x -= 1;
                this->y += 1;

            }
            break;
        }
        case NE: {
            if (validMove(this->x + 1, this->y + 1)) {
                moved = true;
                this->breedTicks++;
                this->starvation++;
                city->setOrganism(NULL, x, y);
                city->setOrganism(this, x + 1, y + 1);
                this->x += 1;
                this->y += 1;

            }
            break;
        }
        case SE: {
            if (validMove(this->x + 1, this->y - 1)) {
                moved = true;
                this->breedTicks++;
                this->starvation++;
                city->setOrganism(NULL, x, y);
                city->setOrganism(this, x + 1, y - 1);
                this->x += 1;
                this->y -= 1;

            }
            break;
        }
        case SW: {
            if (validMove(this->x- 1, this->y - 1)) {
                moved = true;
                this->breedTicks++;
                this->starvation++;
                city->setOrganism(NULL, x, y);
                city->setOrganism(this, x - 1, y - 1);
                this->x -= 1;
                this->y -= 1;

            }
            break;
        }
            default: {
                moved = true;
                this->breedTicks++;
                this->starvation++;
                break;
            }
        }//END OF SWITCH MOVE
    }//VECTOR EMPTY

}//END MOVE



void Zombie::eat() {
    using namespace std;
//    vector<City> moveTargets;
    vector<int> moveTargets;

    if (validEat(this->x - 1, this->y + 1)) {
        moveTargets.push_back(NE);
    }
    if (validEat(this->x, this->y + 1)) {
        moveTargets.push_back(N);
    }
    if (validEat(this->x - 1, this->y + 1)) {
        moveTargets.push_back(NW);
    }
    if (validEat(this->x + 1, this->y)) {
        moveTargets.push_back(E);
    }
    if (validEat(this->x - 1, this->y - 1)) {
        moveTargets.push_back(SW);
    }
    if (validEat(this->x, this->y - 1)) {
        moveTargets.push_back(S);
    }
    if (validEat(this->x + 1, this->y - 1)) {
        moveTargets.push_back(SE);
    }
    if (validEat(this->x - 1, this->y)) {
        moveTargets.push_back(W);
    }
//SHUFFLE


    if (!moveTargets.empty()) {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(moveTargets.begin(), moveTargets.end(), default_random_engine(seed));

        switch (moveTargets[0]) {
            case N: {
                if (city->getOrganism(x, y + 1) != NULL && (city->getOrganism(x, y + 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y + 1);
                    this->y += 1;
                    this->starvation=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    hasEaten = true;
                    moved = true;
                }
                break;
            }
            case S: {
                if (city->getOrganism(x, y - 1) != NULL && (city->getOrganism(x, y - 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y - 1);
                    this->y -= 1;
                    this->starvation=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    hasEaten = true;
                    moved = true;
                }
                break;
            }

            case W: {
                if (city->getOrganism(x - 1, y) != NULL && (city->getOrganism(x - 1, y))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y);
                    this->x -= 1;
                    this->starvation=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    hasEaten = true;
                    moved = true;
                }
                break;
            }
            case E: {
                if (city->getOrganism(x + 1, y) != NULL && (city->getOrganism(x + 1, y))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x + 1, y);
                    this->x += 1;
                    this->starvation=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    hasEaten = true;
                    moved = true;
                }
                break;
            }

            case NW: {
                if (city->getOrganism(x - 1, y + 1) != NULL && (city->getOrganism(x - 1, y + 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y + 1);
                    this->x -= 1;
                    this->y += 1;
                    this->starvation=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    hasEaten = true;
                    moved = true;
                    break;
                }
                case NE: {
                    if (city->getOrganism(x + 1, y + 1) != NULL &&
                        (city->getOrganism(x + 1, y + 1))->getSpecies() == 1) {
                        city->setOrganism(NULL, x, y);
                        city->setOrganism(this, x + 1, y + 1);
                        this->x += 1;
                        this->y += 1;
                        this->starvation=0;
                        this->breedTicks++;
                        this->city->eaten++;
                        hasEaten = true;
                        moved = true;
                    }
                    break;
                }
                case SE:
                    if (city->getOrganism(x + 1, y - 1) != NULL &&
                        (city->getOrganism(x + 1, y - 1))->getSpecies() == 1) {
                        city->setOrganism(NULL, x, y);
                        city->setOrganism(this, x + 1, y - 1);
                        this->x += 1;
                        this->y -= 1;
                        this->starvation=0;
                        this->breedTicks++;
                        this->city->eaten++;
                        hasEaten = true;
                        moved = true;
                    }
                break;
            }
            case SW: {
                if (city->getOrganism(x - 1, y - 1) != NULL && (city->getOrganism(x - 1, y - 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y - 1);
                    this->x -= 1;
                    this->y -= 1;
                    this->starvation=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    hasEaten = true;
                    moved = true;
                }
                break;
            }
            default: {

                break;
            }
        }//END OF SWITCH MOVE

    }//VECTOR EMPTY


        moveTargets.clear();

}

Zombie::Zombie() {

}

Zombie::Zombie(City *city, int x, int y) : Organism(city, x, y) {

}

Zombie::~Zombie() {

}
//END OF EAT






