#include "coordinate.h"

Coordinate::Coordinate()
{
   xKoordinate=-1;
   yKoordinate=-1;
   hasFood=false;
   hasSnake=false;
}
Coordinate::Coordinate(int x, int y, bool hasFood, bool hasSnake)
{
   xKoordinate=x;
   yKoordinate=y;
   this->hasFood=hasFood;
   this->hasSnake=hasSnake;
}

void Coordinate::setXKoordinate(int x)
{
 this->xKoordinate =x;
}
void Coordinate::setYKoordinate(int y)
{
    this->yKoordinate = y;
}
int  Coordinate::getXKoordinate()
{
    return xKoordinate;
}
int  Coordinate::getYKoordinate()
{
    return yKoordinate;
}

bool Coordinate::getHasFood() const
{
    return hasFood;
}

void Coordinate::setHasFood(bool value)
{
    hasFood = value;
}

bool Coordinate::getHasSnake() const
{
    return hasSnake;
}

void Coordinate::setHasSnake(bool value)
{
    hasSnake = value;
}

bool Coordinate::getHasPoop() const
{
    return hasPoop;
}

void Coordinate::setHasPoop(bool value)
{
    hasPoop = value;
}
//bool Coordinate::operator==(const Coordinate &a, const Coordinate &b)
//{
//    if(a.xKoordinate == b.xKoordinate && a.yKoordinate== b.yKoordinate)
//        return true;
//    return false;
//}
