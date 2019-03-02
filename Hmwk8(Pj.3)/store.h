#ifndef STORE_H //All caps version of class name.
#define STORE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Store
{
    private:
        int oxenPrice;
        float foodPrice;
        int medicalKitPrice;
        int bulletsPrice;
        int wagonPartsPrice;
        
        
    
    public:
        Store();
        int getOxenPrice(int); //Takes an integer for how many oxen I purchase and returns the total cost.
        float getFoodPrice(int);
        int getMedicalKitPrice(int);
        int getBulletsPrice(int);
        int getWagonPartsPrice(int);
};

#endif