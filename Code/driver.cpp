#include "players.cpp"
#include "store.cpp"
#include "date.cpp"
#include "position.cpp"
#include "game.cpp"

using namespace std;

/*
Rule of thumb: Handle edge cases first!!
Questions: I am wondering: in the input parameter of a function, can I put a private data member and not declare the type? Since it is already pre declared?
Errors:Learn difference between break, continue, and return.




Algorithm:
1.) Complete my function which takes in the milestones.txt as a string input parameter.
    1.) Write a split function (preferebly using stringstream) to split up the text into type, name, and distance.
    2.) I am going to have to keep in mind that rivers have a depth to them. Haven't added them yet.
    3.) ifstream is for reading, ofstream is for writing, fstream is for both. Syntax: myFileVariable.is_open() - Because is a function.
2.) Fill out my destructor for if a player dies, then do something. Not sure entirely how to fill out yet.
3.) Do my menu function in store.cpp.
    1.) Should set the player's current money to a new value after they purchase something.
    2.) Should also change the price in everything in the store according to where the player is. Will get more expensive as it goes on.
4.) In position.cpp.
    1.) I need to figure out a way to fix my position array issue. I think that the problem is that I cannot have an array of the class type in that same class. I think I will have to do it in another class or file or something like that.
    2.) Based on the current position in the array, I will want to return certain values, such as: type, name, and distance (position). This will not be too hard to do.

*/

//Can declare object like: Date d. Which will make an object called d of the date class. Since no paretheneses, will give prpoerties of defualt constructor. Or: Date d = Date(). This means object of date type is equal to the constructor with these input parameters.
int main()
{
    srand(time(0));
    cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE MISSOURI TO OREGON CITY, OREGON IN 1847." << endl;
    cout << "YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl;
    cout << endl;
    Game g; //Makes an instance of class Game.
    g.makeNewPlayer(); //Calls this function using the class Game.
    g.storeInterface();
    g.startingDate(); //This long number is the default starting date.
    g.turns();
    //g.raiderAttack(); //For testing.
    //g.misfortunes(); //For testing.
}