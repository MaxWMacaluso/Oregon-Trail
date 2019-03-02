#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>
#include "players.h"
#include "store.h"
#include "date.h"
#include "position.h"

using namespace std;


/*Have to do:
4.) Misfortunes
*/
class Game
{
    private:
        Players playersArray[5]; //Is an array that contains all of my players.
        Store store;
        Date defualtDate; //Will be automatically set equal to the defualt constructor.
        Date customDate;
        int counter; //For how many stores I have been to. Affects multiplyer.
        float mult;
        int playerCount;
        bool quit; //Will make the while loop stop working and will go to an if statement that will break the code by returning.
    
    public:
        Game();
        void makeNewPlayer(); //Done.
        void storeInterface(); //Done.
        void startingDate(); //Done
        void turns(); //Rest is done. Need to do continue and hunt.
        int randomNumbers(int, int); //For min and max. WIll return a random number.
        bool quiz(); //Will return true if the user guessed the right number, false if they didnt. Will automatically go through 3 times. So just check if it returns true.
        void raiderAttack();
        void misfortunes();
        int alivePlayerCounter();
};

#endif