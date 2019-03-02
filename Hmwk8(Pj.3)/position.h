#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Position //The position class is made up of the private data members. IE the object is defined as everything in the private data members and, most of the time, the public section is for accessing/altering those private data members.
{
   private:
   string name;
   string type;
   int distance;
   int depth;
   
   public:
   Position(); //Default constructor
   Position(string, string, int, int); //Constructor.
   string getName();
   string getType();
   void setDistance(int);
   int getDistance();
   void setDepth(int);
   int getDepth();
   
};

#endif