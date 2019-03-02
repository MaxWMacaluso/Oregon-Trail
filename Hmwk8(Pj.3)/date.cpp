#include "date.h"

using namespace std;

Date::Date()
{
    year = 1847;
    day = 28;
    month = 3;
}

Date::Date(int month2, int day2)
{
    year = 1847;
    day = day2;
    month = month2;
}

 void Date::setDay(string userDate)
 {
     string stringDay;
     string stringMonth;
     stringstream ss(userDate);
     getline(ss, stringMonth, '/'); //Gets the line from the ss stringstream, stores everyting before slash in '/'.
     getline(ss, stringDay, '/');
     day = stoi(stringDay);
 }

int Date::getDay()
{
    return day;
}

void Date::setMonth(string userDate) //Need to fill in.
{
     string stringDay;
     string stringMonth;
     stringstream ss(userDate);
     getline(ss, stringMonth, '/'); //Gets the line from the ss stringstream, stores everyting before slash in '/'.
     getline(ss, stringDay, '/');
     month = stoi(stringMonth);
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

//Below function is for traveling turn.
void Date::continueTurnAddDate() //Here is where I have a function that will add to date and such. If I actually want to implement, I need to do in game.h.
{
    day = day + 14;
    if (day > 30)
    {
        month++;
        day = day - 30;
    }
}
//Below function is for resting. Takes radnomely inbetween 2-3 days.
void Date::restTurnAddDate(int userInput)
{
    day = day + userInput;
    if (day > 30)
    {
        month++;
        day = day - 30;
    }
}
//For hunting turn.
void Date::huntTurnAddDate()
{
    day = day + 1;
    if (day > 30)
    {
        month++;
        day = day - 30;
    }
}
