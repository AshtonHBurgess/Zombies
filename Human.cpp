#include "Human.h"

Human::Human() {

}

Human::Human(City *city, int x, int y) : Organism(city, x, y) {

}

bool Human::validMove(int cordinateX, int cordinateY) {

    if((cordinateX>=0 && cordinateX<GRIDSIZE && cordinateY>=0 && cordinateY<GRIDSIZE)&& (city->grid[cordinateX][cordinateY] == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}



void Human::spawn() {
//                enum direction_NUM{N=1, S=2, W=3,E=4,NW=5,NE=6,SE=7,SW=8 };
//
    if  (this->breedTicks >= HUMAN_BREED)
    {

        using namespace std;
//    vector<City> moveTargets;
        vector<int> moveTargets ;

//    if (validMove(this->x - 1, this->y+1)) {
//        moveTargets.push_back(NE);
//    }
        if (validMove(this->x , this->y+1)) {
            moveTargets.push_back(N);
        }
//    if (validMove(this->x+1, this->y+1)) {
//        moveTargets.push_back(NW);
//    }
        if (validMove(this->x+1, this->y)) {
            moveTargets.push_back(E);
        }
//    if (validMove(this->x+1, this->y-1)) {
//        moveTargets.push_back(SW);
//    }
        if (validMove(this->x, this->y-1)) {
            moveTargets.push_back(S);
        }
//    if (validMove(this->x-1, this->y-1)) {
//        moveTargets.push_back(SE);
//    }
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

            }
            this->breedTicks=0;
            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        case S: {
            if (validMove(this->x, this->y - 1)) {
                Human *human = new Human(city,x,y-1);
            }
            this->breedTicks=0;
            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        case W: {
            if (validMove(this->x - 1, this->y)) {
                Human *human = new Human(city,x-1,y);
            }
            this->breedTicks=0;
            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        case E: {
            if (validMove(this->x + 1, this->y)) {
                Human *human = new Human(city,x+1,y);
            }
            this->breedTicks=0;
            std::cout<<"Human recruited"<<std::endl;
            break;
        }
        default:
            //NO Available Positions
        {
            this->breedTicks=0;
            break;
        }
    }//END OF SWITCH MOVE

}//IF VECTOR EMPTY
    }//IF BREED COUNTER == BREED COUNTER

}//END OF SPA ZOMBIE




void Human::move() {
    using namespace std;
//    vector<City> moveTargets;
    vector<int> moveTargets ;

//    if (validMove(this->x - 1, this->y+1)) {
//        moveTargets.push_back(NE);
//    }
    if (validMove(this->x , this->y+1)) {
        moveTargets.push_back(N);
    }
//    if (validMove(this->x+1, this->y+1)) {
//        moveTargets.push_back(NW);
//    }
    if (validMove(this->x+1, this->y)) {
        moveTargets.push_back(E);
    }
//    if (validMove(this->x+1, this->y-1)) {
//        moveTargets.push_back(SW);
//    }
    if (validMove(this->x, this->y-1)) {
        moveTargets.push_back(S);
    }
//    if (validMove(this->x-1, this->y-1)) {
//        moveTargets.push_back(SE);
//    }
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
                    moved = true;
                    this->breedTicks++;
                }
                break;
            }
            case S: {
                if (validMove(this->x, this->y - 1)) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x, y - 1);
                    this->y -= 1;
                    moved = true;
                    this->breedTicks++;
                }
                break;
            }
            case W: {
                if (validMove(this->x - 1, this->y)) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x - 1, y);
                    this->x -= 1;
                    moved = true;
                    this->breedTicks++;

                }
                break;
            }
            case E: {
                if (validMove(this->x + 1, this->y)) {
                    city->setOrganism(NULL, x, y);
                    city->setOrganism(this, x + 1, y);
                    this->x += 1;
                    moved = true;
                    this->breedTicks++;
                }
                break;
            }
//        case NW: {
//            if (validMove(this->x - 1, this->y + 1)) {
//                city->setOrganism(NULL, x, y);
//                city->setOrganism(this, x - 1, y + 1);
//                this->x -= 1;
//                this->y += 1;
//                moved = true;
//                this->breedTicks++;
//            }
//            break;
//        }
//        case NE: {
//            if (validMove(this->x + 1, this->y + 1)) {
//                city->setOrganism(NULL, x, y);
//                city->setOrganism(this, x + 1, y + 1);
//                this->x += 1;
//                this->y += 1;
//                moved = true;
//                this->breedTicks++;
//            }
//            break;
//        }
//        case SE: {
//            if (validMove(this->x + 1, this->y - 1)) {
//                city->setOrganism(NULL, x, y);
//                city->setOrganism(this, x + 1, y - 1);
//                this->x += 1;
//                this->y -= 1;
//                moved = true;
//                this->breedTicks++;
//            }
//            break;
//        }
//        case SW: {
//            if (validMove(this->x- 1, this->y - 1)) {
//                city->setOrganism(NULL, x, y);
//                city->setOrganism(this, x - 1, y - 1);
//                this->x -= 1;
//                this->y -= 1;
//                moved = true;
//                this->breedTicks++;
//            }
//            break;
//        }
            default: {
                moved = true;
                breedTicks++;
                break;
            }
        }//END OF SWITCH MOVE
    }//VECTOR EMPTY

}//END MOVE

int Human::getSpecies() {
    return 1;
}

bool Human::starve() {
    //humans dont starve
    return false;
}

void Human::eat() {

}
