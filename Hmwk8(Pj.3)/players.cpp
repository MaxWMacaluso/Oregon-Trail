#include<iostream>
#include "players.h"
using namespace std;

Players::Players() //Defualt constructor. Sets the player's private data members equal to the starting values. Initialize private data members here.
{
    playerName = "";
    playerMoney = 1000;
    oxen = 0;
    food = 0;
    wagonParts = 0;
    playerHealth = 100;
    playerPosition = 0;
    wagon = 1;
    currentDate = Date(); //Optional. Program automatically sets new object equal to defualt constructor. Here, I am doing same thing as initilizing a normal variable, except the program automatically uses the defualt unless I say otherwise.
    distanceToLandmark = 102;
    numTurns = 0;
    bullets = 10;
    medicalKit = 0;
    elementPosition = 0;
    alive = true;
}

Players::Players(string name) //Constructor. Sets private data members equal to the starting values/what the input parameters are for the constructor.
{
    playerName = name;
    playerMoney = 1000;
    oxen = 0;
    food = 0;
    wagonParts = 0;
    playerHealth = 100;
    playerPosition = 0;
    wagon = 1;
    currentDate; //Here I never set it to a value because the program will automatically use the defualt constructor unless said otherwise.
    distanceToLandmark = 102;
    numTurns = 0;
    bullets = 10;
    medicalKit = 0;
    elementPosition = 0;
    alive = true;
}

void Players::setMoney(float cost, float mult)
{
    if (alive)
    {
        playerMoney = playerMoney - (cost * mult);
    }
}

float Players::getMoney()
{
    return playerMoney;
}

void Players::setOxen(int currentOxen, int subtraction)
{
    if (alive)
    {
        oxen = currentOxen - subtraction;
    }
}

void Players::setFood(int currentFood, int foodSubtraction) //For food subtraction.
{
    if (alive)
    {
        food = currentFood - foodSubtraction;
    }
}

void Players::setWagonParts(int currentWagonParts, int subtraction)
{
    if (alive)
    {
        wagonParts = currentWagonParts - subtraction;
    }
}

int Players::getOxen() //Functions from the same class as a private variable can return that private variable. Have to do getter function because, for example, I cannot do: playerClassObject.oxen. I have to make a function that returns that value.
{
    return oxen;
}

int Players::getFood()
{
    return food;
}

int Players::getWagonParts()
{
    return wagonParts;
}

string Players::getName()
{
    return playerName;
}

void Players::setBullets(int currentBullets)
{
    if (alive)
    {
        bullets = (currentBullets * 20); //Here I am converting boxes of bullets to individual bullets.
    }
}

int Players::getBullets()
{
    return bullets;
}

void Players::setMedicalKit(int currentMedicalKit)
{
    if (alive)
    {
        medicalKit = currentMedicalKit;
    }
}

int Players::getMedicalKit()
{
    return medicalKit;
}

void Players::setPlayerHealth(int currentPlayerHealth, int subtraction, int addition)
{
    if (alive) //Will only add if the player is alive.
    {
        playerHealth = currentPlayerHealth - subtraction + addition;
    }
    if (playerHealth == 0) //If the health is equal to 0 then they are sick.
    {
        alive = true;
    }
    if (playerHealth < 0) //If it is less than 0 then they are dead.
    {
        alive = false;
    }
}

int Players::getPlayerHealth()
{
    return playerHealth;
}

void Players::setPlayerPosition(int position) //Will add the position to the player's overall position.
{
    if (alive)
    {
        playerPosition = playerPosition + position;
    }
}

int Players::getPlayerPosition()
{
    return playerPosition;
}

void Players::setWagon(int numWagon) //Takes input parameter of integer type called numWagon.
{
    wagon = numWagon;
}

int Players::getWagon()
{
    return wagon;
}

void Players::setCurrentDate(Date userDates) //Takes input parameter of Date type called userDates. Date type must have int month and int day in that order.
{
    if (alive)
    {
        currentDate = userDates;
    }
}

Date Players::getCurrentDate() //Returns a value of the date class. If I want to get a private member of that class, just call the function now since Im now in that class.
{
    return currentDate;
}

void Players::setDistanceToLandmark(int position, string fileName) //This input parameter will be the current value for playerPosition.
{
    ifstream mileStoneReader; //Making File IO variable named mileStoneReader.
    mileStoneReader.open(fileName); //Opens the file with given name.
    if (mileStoneReader.is_open()) //If it is open
    {
        int counter = 0;
        string line = "";
        string name = "";
        string distance = ""; //Need to convert
        string type = ""; 
        string depth = ""; //Need to convert. 0 if not river.
        while (getline(mileStoneReader, line)) //Will go though each line of the file and store the current line in the string variable line.
        {
            stringstream ss(line); //Makes a stringstream variable named ss with the input of the string line.
            getline(ss, name, ','); //Stores everything before the first comma in name.
            getline(ss, distance, ','); //Will need to converto to int later. Stores everything inebetween first and second into distance.
            getline(ss, type, ','); //Will store everything betweeen second and third into type.
            getline(ss, depth); //Will store everything afterwards into depth.
            Position positions(name, type, stoi(distance), stoi(depth)); //Declare object first. Input parameter of object is the constructor's input parameters.
            positionArray[counter] = positions; //Then set array equal to object. Value of object will change along with each element of the array.
            counter++; //Will incremement as long as it can get a line, ie for how many milestones there are.
            
        }
        mileStoneReader.close();
    }
    else
    {
        cout << "Something went wrong!" << endl;
    }
    
    for (int x = 0; x < 15; x++)
    {
        if (positionArray[x].getDistance() < playerPosition)
        {
            continue;
        }
        else if (positionArray[x].getDistance() > playerPosition  && (positionArray[x].getDistance() - playerPosition <= 140))
        {
            elementPosition = x; //Element position is equal to the element in the array where they can reach the next landmark.
            distanceToLandmark = positionArray[elementPosition].getDistance() - playerPosition;
        }
    }
}

Position Players::getMileStone(int element) //Gets the milestone at a corrsponding position. Corresponds with getMileStonePosition function.
{
    return positionArray[element];
}

int Players::getDistanceToLandmark()
{
    return distanceToLandmark;
}

void Players::increasePlayerTurnCount(int numberOfTurns)
{
    numTurns = numTurns + numberOfTurns;
}

int Players::getPlayerTurnCount()
{
    return numTurns;
}

int Players::getMileStonePosition()
{
    return elementPosition;
}

void Players::setAlive(bool TF) //If true, then alive. If false, dead. Havent used this yet.
{
    alive = TF;
}

bool Players::getAlive()
{
    return alive; //True is alive, false, is dead.
}
void Players::setFoodAdding(int currentFood, int foodAddition) //For addition of food.
{
    if (alive)
    {
        food = currentFood + foodAddition;
    }
}
void Players::setBulletsSubtraction(int currentBullets,int subtraction)
{
    if (alive)
    {
        bullets = currentBullets - subtraction;
    }
}

void Players::setBulletsAdding(int currentBullets, int addition)
{
    if (alive)
    {
        bullets = currentBullets + addition;
    }
}

void Players::setMoneyProbability(int currentMoney, int subtraction)
{
    if (alive)
    {
        playerMoney = currentMoney - subtraction;
    }
}