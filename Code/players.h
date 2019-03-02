#ifndef PLAYERS_H
#define PLAYERS_H //Want to include all of below

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>
#include "position.h"
#include "date.h"

using namespace std; //Cannot access objects of a class in same class. For example, I cannot make a Players object in this class since I am in the Players class.

class Players
{
    private:
    string playerName;
    float playerMoney;
    int oxen;
    int food;
    int wagonParts;
    int bullets; //Not boxes.
    int medicalKit;
    int playerHealth;
    int playerPosition;
    Position positionArray[15]; //Is of size 15. I need to ask about this. I can't have an array of a certain class in its own class.
    int wagon;
    Date currentDate; //Is of the date type.
    int distanceToLandmark;
    int numTurns; //Everyturn I have to increment by one.
    int elementPosition; //Is position in the position array.
    bool alive; //Equals alive if true, false, if dead.
    
    public:
    Players(string); //Constructor. Doesn't need name because is in header file. Only data type.
    Players(); //Defualt constructor.
    void setMoney(float, float); //Helper function. Will set the money to certain values based on what they purchase at the store (in the store class)
    float getMoney(); //Helper function. Will return the amount of money. Dont need an input parameter because just returning something.
    void setOxen(int, int);
    void setFood(int, int);
    void setWagonParts(int, int);
    int getOxen();
    int getFood();
    int getWagonParts();
    string getName(); //Dont need a set name bceause I essentially do that in my constructor and I will not be changing the names later.
    void setBullets(int); //Will set the bullets equal to the number of boxes times 20.
    int getBullets();
    void setMedicalKit(int);
    int getMedicalKit();
    void setPlayerHealth(int, int, int);
    int getPlayerHealth();
    void setPlayerPosition(int); //Each time the user chooses the "continue" option, this function will be called.
    int getPlayerPosition();
    void setWagon(int);
    int getWagon();
    void setCurrentDate(Date); //Takes input parameter for Date class, or type. which takes input of day/month.
    Date getCurrentDate(); //Returns a date type. Is specific to each user.
    void setDistanceToLandmark(int, string); //Takes input paramater for current player position and a input parameter for the milestones text. This function subtracts current position from the element (number of turns) in the position array of positions.
    int getDistanceToLandmark();
    void increasePlayerTurnCount(int); //Int is for how many days I want to increase it by.
    int getPlayerTurnCount();
    Position getMileStone(int);
    int getMileStonePosition(); //returns position of element in position array.
    void setAlive(bool);
    bool getAlive(); //Returns if alive or dead.
    void setFoodAdding(int, int);
    void setBulletsSubtraction(int, int); //For when I subtract bullets.
    void setBulletsAdding(int, int);
    void setMoneyProbability(int, int);
    //void setSick(int);
    
    
    
};

#endif 