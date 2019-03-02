#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
    
    public:
        Date(); //Defualt constructor.
        Date(int, int);
        void setDay(string); //Doesn't return anything just sets a value to what the user inputs. Is the setter.
        int getDay(); //Doesnt do anything, just returns the value of the private.
        void setMonth(string);
        int getMonth();
        int getYear();
        void continueTurnAddDate(); //Next three functions are different options for the turn class.
        void restTurnAddDate(int);
        void huntTurnAddDate();
        
    
    
};

#endif