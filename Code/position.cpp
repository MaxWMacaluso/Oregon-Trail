#include "position.h"

using namespace std;

Position::Position() //Default constructor
{
    name = "";
    type = "";
    distance = 0;
    depth = 0;
}

Position::Position(string name2, string type2, int distance2, int depth2)
{
    name = name2;
    type = type2;
    distance = distance2;
    depth = depth2;
}

string Position::getName() //Gets the player's location name.
{
    return name;
}

string Position::getType() //Get's the player's location type.
{
    return type;
}

void Position::setDistance(int distance2)
{
    distance = distance2;
}

int Position::getDistance()
{
    return distance;
}

void Position::setDepth(int depth2)
{
    depth = depth2;
}

int Position::getDepth()
{
    return depth;
}