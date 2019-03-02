#include "store.h"

using namespace std;

Store::Store()
{
    oxenPrice = 20;
    foodPrice = .5;
    medicalKitPrice = 25;
    bulletsPrice = 2;
    wagonPartsPrice = 20;
}

int Store::getOxenPrice(int numOfOxen)
{
    return numOfOxen * oxenPrice;
}

float Store::getFoodPrice(int numOfFood)
{
    return numOfFood * foodPrice;
}

int Store::getMedicalKitPrice(int numOfMedicalKits)
{
    return numOfMedicalKits * medicalKitPrice;
}

int Store::getBulletsPrice(int numOfBullets) //numOfBullets is how many boxes, not indivual quanitity.
{
    return numOfBullets * bulletsPrice;
}

int Store::getWagonPartsPrice(int numOfWagonParts)
{
    return numOfWagonParts * wagonPartsPrice;
}

/*float Store::menu(float money, int currentPosition) //This will change the prices of everything in the store depending on the current user position (2n input parameter). The input parameter of money will be the current money that the player has.
{
    //Something needs to go here later. Should set the player's current money to how much they would have left after purchasing (return that value). And another little function to change the store price depending on the position.
    //Believe i would do like: playerObject.setMoney(what is left after purchasing.)
}*/