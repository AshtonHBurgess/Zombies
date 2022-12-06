//
// Created by asbur on 11/29/2022.
//
#include "Zombie.h"
#include "Human.h"

bool Zombie::validMove(int cordinateX, int cordinateY)  {
    if((cordinateX>=0 && cordinateX<GRIDSIZE)
       && (cordinateY>=0 && cordinateY<GRIDSIZE)
       && (city->grid[cordinateX][cordinateY] == NULL)
//    && (city->grid[cordinateX][cordinateY]->getSpecies() != 2)
//    && ( city->grid[cordinateX][cordinateY]->getSpecies() !=1 )
            )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//
//    if(
//            (cordinateX>=0 && cordinateX<GRIDSIZE)
//       && (cordinateY>=0 && cordinateY<GRIDSIZE)
//       && (city->grid[cordinateX][cordinateY] != NULL)
//            )
//    {//NULL makes sure there's no organism in that location
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

bool Zombie::validEat(int cordinateX, int cordinateY) {
    if(
            (cordinateX>=0 && cordinateX<GRIDSIZE)
            && (cordinateY>=0 && cordinateY<GRIDSIZE)
            && (city->grid[cordinateX][cordinateY] != NULL)
            && (city->grid[cordinateX][cordinateY]->getSpecies() != 2)
            && ( city->grid[cordinateX][cordinateY]->getSpecies() ==1 )
            )
    {//NULL makes sure there's no organism in that location
        return true;
    }
    else
    {
        return false;
    }
}


//
//
//void Zombie::move() {
//    using namespace std;
//
////    vector<City> moveTargets;
//    vector<int> moveTargets ;
//
//    if (validMove(this->x , this->y+1)) {
//        moveTargets.push_back(N);
//    }
//
//    if (validMove(this->x+1, this->y)) {
//        moveTargets.push_back(E);
//    }
//
//    if (validMove(this->x, this->y-1)) {
//        moveTargets.push_back(S);
//    }
//
//    if (validMove(this->x-1, this->y)) {
//        moveTargets.push_back(W);
//    }
////SHUFFLE
//
//    if(!moveTargets.empty()) {
//        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
//        shuffle(moveTargets.begin(), moveTargets.end(), default_random_engine(seed));
//
//        switch (moveTargets[0]) {
//            case N: {
//                if (validMove(this->x, this->y + 1)) {
//                    city->setOrganism(NULL, x, y);
//                    city->setOrganism(this, x, y + 1);
//                    this->y += 1;
//                    this->breedTicks++;
//                }
//                break;
//            }
//            case S: {
//                if (validMove(this->x, this->y - 1)) {
//                    city->setOrganism(NULL, x, y);
//                    city->setOrganism(this, x, y - 1);
//                    this->y -= 1;
//                    this->breedTicks++;
//                }
//                break;
//            }
//            case W: {
//                if (validMove(this->x - 1, this->y)) {
//                    city->setOrganism(NULL, x, y);
//                    city->setOrganism(this, x - 1, y);
//                    this->x -= 1;
//                    this->breedTicks++;
//                }
//                break;
//            }
//            case E: {
//                if (validMove(this->x + 1, this->y)) {
//                    city->setOrganism(NULL, x, y);
//                    city->setOrganism(this, x + 1, y);
//                    this->x += 1;
//                    this->breedTicks++;
//                }
//                break;
//            }
//            default: {
//                break;
//            }
//        }//END OF SWITCH MOVE
//    }//VECTOR EMPTY
//    moveTargets.clear();
//}//END MOVE


void Zombie::spawn() {
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
                    Zombie *z = new Zombie(this->city,x,y+1);
                        city->setOrganism(z, x, y + 1);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case S: {
                    Zombie *z = new Zombie(this->city,x,y-1);
                        city->setOrganism(z, x, y - 1);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case W: {
                    Zombie *z = new Zombie(this->city,x-1,y);
                        city->setOrganism(z, x-1, y);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case E: {
                    Zombie *z = new Zombie(this->city,x+1,y);
                        city->setOrganism(z, x+1, y);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case NW: {
                    Zombie *z = new Zombie(this->city,x-1,y+1);
                        city->setOrganism(z, x-1, y + 1);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case NE: {
                    Zombie *z = new Zombie(this->city,x+1,y+1);
                        city->setOrganism(z, x+1, y + 1);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case SW: {
                    Zombie *z = new Zombie(this->city,x-1,y-1);
                        city->setOrganism(z, x-1, y - 1);

                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
                    break;
                }
                case SE: {
                    Zombie *z = new Zombie(this->city,x+1,y-1);
                        city->setOrganism(z, x+1, y -1);
                    city->converted++;
//                    std::cout<<"Zombie recruited"<<std::endl;
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



void Zombie::move() {
    using namespace std;
//    cout<<"z move";
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

                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y + 1);
                    this->y += 1;
                    this->breedTicks++;
                    this->starveCount++;
                }
                break;
            }
            case S: {
                if (validMove(this->x, this->y - 1)) {
                    city->setOrganism(this, x, y - 1);
                    city->setOrganism(NULL, x, y);
                    this->y -= 1;
                    this->breedTicks++;
                    this->starveCount++;

                }
                break;
            }
            case W: {
                if (validMove(this->x - 1, this->y)) {
                    city->setOrganism(this, x - 1, y);
                    city->setOrganism(NULL, x, y);
                    this->x -= 1;
                    this->breedTicks++;
                    this->starveCount++;


                }
                break;
            }
            case E: {
                if (validMove(this->x + 1, this->y)) {
                    city->setOrganism(this, x + 1, y);
                    city->setOrganism(NULL, x, y);
                    this->x += 1;
                    this->breedTicks++;
                    this->starveCount++;

                }
                break;
            }
        case NW: {
            if (validMove(this->x - 1, this->y + 1)) {
                city->setOrganism(this, x - 1, y + 1);
                city->setOrganism(NULL, x, y);
                this->x -= 1;
                this->y += 1;
                this->breedTicks++;
                this->starveCount++;

            }
            break;
        }
        case NE: {
            if (validMove(this->x + 1, this->y + 1)) {
                city->setOrganism(this, x + 1, y + 1);
                city->setOrganism(NULL, x, y);
                this->x += 1;
                this->y += 1;
                this->breedTicks++;
                this->starveCount++;

            }
            break;
        }
        case SE: {
            if (validMove(this->x + 1, this->y - 1)) {
                city->setOrganism(this, x + 1, y - 1);
                city->setOrganism(NULL, x, y);
                this->x += 1;
                this->y -= 1;
                this->breedTicks++;
                this->starveCount++;

            }
            break;
        }
        case SW: {
            if (validMove(this->x- 1, this->y - 1)) {
                city->setOrganism(this, x - 1, y - 1);
                city->setOrganism(NULL, x, y);
                this->x -= 1;
                this->y -= 1;
                this->breedTicks++;
                this->starveCount++;

            }
            break;
        }
            default: {
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
                    this->starveCount=0;
                    this->breedTicks++;
                    this->city->eaten++;
                }
                break;
            }
            case S: {
                if (city->getOrganism(x, y - 1) != NULL && (city->getOrganism(x, y - 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y - 1);
                    this->y -= 1;
                    this->starveCount=0;
                    this->breedTicks++;
                    this->city->eaten++;
                }
                break;
            }

            case W: {
                if (city->getOrganism(x - 1, y) != NULL && (city->getOrganism(x - 1, y))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y);
                    this->x -= 1;
                    this->starveCount=0;
                    this->breedTicks++;
                    this->city->eaten++;
                }
                break;
            }
            case E: {
                if (city->getOrganism(x + 1, y) != NULL && (city->getOrganism(x + 1, y))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x + 1, y);
                    this->x += 1;
                    this->starveCount=0;
                    this->breedTicks++;
                    this->city->eaten++;
                }
                break;
            }

            case NW: {
                if (city->getOrganism(x - 1, y + 1) != NULL && (city->getOrganism(x - 1, y + 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y + 1);
                    this->x -= 1;
                    this->y += 1;
                    this->starveCount=0;
                    this->breedTicks++;
                    this->city->eaten++;
                    break;
                }
                case NE: {
                    if (city->getOrganism(x + 1, y + 1) != NULL &&
                        (city->getOrganism(x + 1, y + 1))->getSpecies() == 1) {
                        city->setOrganism(NULL, x, y);
                        city->setOrganism(this, x + 1, y + 1);
                        this->x += 1;
                        this->y += 1;
                        this->starveCount=0;
                        this->breedTicks++;
                        this->city->eaten++;
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
                        this->starveCount=0;
                        this->breedTicks++;
                        this->city->eaten++;
                    }
                break;
            }
            case SW: {
                if (city->getOrganism(x - 1, y - 1) != NULL && (city->getOrganism(x - 1, y - 1))->getSpecies() == 1) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y - 1);
                    this->x -= 1;
                    this->y -= 1;
                    this->starveCount=0;
                    this->breedTicks++;
                    this->city->eaten++;
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

bool Zombie::starve() {
    using namespace std;
    if(this->starveCount >= ZOMBIE_STARVE)
    {

        city->setOrganism(NULL, x, y);
        Human *h = new Human(this->city, this->x,this->y);
        city->setOrganism(h, x, y);
//        cout<<"Zombie starved"<<endl;
        return true;

    }
    else
        return false;
}
//END OF EAT






