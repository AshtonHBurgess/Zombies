#include "Human.h"

//
//Human::Human() {
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
//Human::Human(City *city, int x, int y) {
//    this->city = city;
//    moved = false;
//    hasEaten = false;
//    breedTicks = 0;
//    this->x=x;
//    this->y=y;
//    starvation=0;
//    city->setOrganism(this,x,y);
//}

bool Human::validMove(int cordinateX, int cordinateY) {
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



void Human::spawn() {
    using namespace std;

    if  (this->breedTicks >= HUMAN_BREED)
    {
        vector<int> moveTargets ;
        if (validMove(this->x , this->y+1)) {
            moveTargets.push_back(N);
        }
        if (validMove(this->x+1, this->y)) {
            moveTargets.push_back(E);
        }
        if (validMove(this->x, this->y-1)) {
            moveTargets.push_back(S);
        }
        if (validMove(this->x-1, this->y)) {
            moveTargets.push_back(W);
        }

//SHUFFLE
if(!moveTargets.empty()){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
    shuffle(moveTargets.begin(),moveTargets.end(),default_random_engine(seed));
    switch (moveTargets[0]) {
        case N: {
            if (validMove(this->x, this->y + 1)) {
                Human *human = new Human(city,x,y+1);
                city->recruited++;

            }
            this->breedTicks=0;
//            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        case S: {
            if (validMove(this->x, this->y - 1)) {
                Human *human = new Human(city,x,y-1);
                city->recruited++;
            }
            this->breedTicks=0;
//            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        case W: {
            if (validMove(this->x - 1, this->y)) {
                Human *human = new Human(city,x-1,y);
                city->recruited++;
            }
            this->breedTicks=0;
//            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        case E: {
            if (validMove(this->x + 1, this->y)) {
                Human *human = new Human(city,x+1,y);
                city->recruited++;
            }
            this->breedTicks=0;
//            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        default:
            //NO Available Positions
        {
//            this->breedTicks=0;
            break;
        }
    }//END OF SWITCH MOVE

}//IF VECTOR EMPTY
    }//IF BREED COUNTER == BREED COUNTER

}//END OF SPA




void Human::move() {
    using namespace std;
//    vector<City> moveTargets;
    vector<int> moveTargets ;

    if (validMove(this->x , this->y+1)) {
        moveTargets.push_back(N);
    }

    if (validMove(this->x+1, this->y)) {
        moveTargets.push_back(E);
    }

    if (validMove(this->x, this->y-1)) {
        moveTargets.push_back(S);
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
                }
                break;
            }
            case S: {
                if (validMove(this->x, this->y - 1)) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y - 1);
                    this->y -= 1;
                    this->breedTicks++;
                }
                break;
            }
            case W: {
                if (validMove(this->x - 1, this->y)) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y);
                    this->x -= 1;
                    this->breedTicks++;
                }
                break;
            }
            case E: {
                if (validMove(this->x + 1, this->y)) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x + 1, y);
                    this->x += 1;
                    this->breedTicks++;
                }
                break;
            }
            default: {
                break;
            }
        }//END OF SWITCH MOVE
    }//VECTOR EMPTY
    moveTargets.clear();
}//END MOVE
int Human::getSpecies() {
    return 1;
}
void Human::eat() {
}
bool Human::validEat(int cordinateX, int cordinateY) {
    return false;
}
Human::Human() {
}
Human::Human(City *city, int x, int y) : Organism(city, x, y) {
}
Human::~Human() {
}
bool Human::starve() {
    return false;
}
