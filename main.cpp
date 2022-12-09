#include <iostream>
#include <chrono>
#include <thread>
#include "GameSpecs.h"
#include "City.h"

//using namespace std;
void ClearScreen()
{using namespace std;
    int x = 0;
    while(x<GRIDSIZE)
    {
        cout << "\n";
        x++;
    }
}
//const int INTERVAL=11;


int main() {
    using namespace std;
    City *city = new City();
    int INTERVAL=PAUSE_SECONDS;//amount of milliseconds paused for
    chrono:: milliseconds interval(INTERVAL);//timer
    int x=0;
    this_thread::sleep_for(interval);//pause execution for (interval amount of time)
    city->printGrid(*city);
    ClearScreen();


    int iteration =0;
    while (city->hasDiversity() || iteration<ITERATIONS) { //while both humans and zombies exist
        iteration++;
        this_thread::sleep_for(interval);//pause execution for (interval amount of time)
        ClearScreen();
        city->move(); //includes all actions
        city->printGrid(*city);

    }//end while

    cout << "GENERATION: " << city->getGeneration() << endl;
    cout << "HUMANS: " << city->countType(1) << endl;
    cout << "ZOMBIES: " << city->countType(2) << endl;
    cout << "HUMANS  EATEN: " << city->getEaten() << endl;
    cout << "Converted: " << city->getConverted() << endl;
    cout << "Recruited: " << to_string(city->getRecruited()) << endl;
    cout << "Cured: " << city->getCured() << endl;
    cout<<"\n\n\n\n";
    cout << "STARTING SPECS: " << endl;
    cout << "HUMANS: " << HUMAN_STARTCOUNT << endl;
    cout << "ZOMBIES: " << ZOMBIE_STARTCOUNT << endl;
    delete city;
}//end main

