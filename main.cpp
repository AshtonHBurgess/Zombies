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
//    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //create empty City

    City *city = new City();


    int INTERVAL=PAUSE_SECONDS;//amount of milliseconds paused for


    chrono:: milliseconds interval(INTERVAL);//timer
    int x=0;
//        while(x<1000){
    this_thread::sleep_for(interval);//pause execution for (interval amount of time)
//            cout<<time<<endl;///Ashton added
//            cout<<*city;//Ashton Added
    city->printGrid(*city);
    ClearScreen();
//            x++;
//        }



//  Populat City



//Do the simulation
    int iteration =0;
//    while (iteration<ITERATIONS) { //while both humans and zombies exist
    while (city->hasDiversity() && iteration<ITERATIONS) { //while both humans and zombies exist
        iteration++;
//        int j =0;
//    while (j<10) { //while both humans and zombies exist
//        j++;
        this_thread::sleep_for(interval);//pause execution for (interval amount of time)

        ClearScreen();
        city->move(); //includes all actions
//        SetConsoleTextAttribute(h,2);
//        cout<<*city;//Ashton Added
        city->printGrid(*city);

// Alternate multi-pass version with each activity happening in its own
// pass through the array. Lends itself to prototyping and testing:
//       city->humansMove();
//       city->zombiesMoveEat();
//       city->humansRecruit();
//       city->zombiesRecruit();
//       city->zombiesStarve();
//       city->countOrganisms(Z or H goes here);
//
//        city->reset(); //resets moved flags
//        city->countOrganisms(Z or H goes here);// run once for each type
//        cout << *city; //prints city

    }//end while
    cout << "GENERATION " << city->getGeneration() << endl;
    cout << "HUMANS: " << to_string(city->countType(1)) << endl;
    cout << "ZOMBIES: " << to_string(city->countType(2)) << endl;

}//end main

