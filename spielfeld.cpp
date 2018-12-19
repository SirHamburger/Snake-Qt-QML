#include "spielfeld.h"

#include <random>
#include <time.h>
unsigned long Spielfeld::sizeX=0;
unsigned long Spielfeld::sizeY=0;

Spielfeld::Spielfeld()
{
    for(int i =0; i< Spielfeld::sizeX; i++)
    {
        feld.push_back(std::vector<Coordinate>());
        for(int j = 0; j < Spielfeld::sizeY; j++)
            feld[i].push_back(Coordinate(j,i,false,false));
    }
    snake.addNewPosition(0,0);
}

void Spielfeld::generateFood()
{
    srand(time(NULL)); // Seed the time
    int x=0;
    int y =0;
    do{
        x= rand()%(Spielfeld::sizeX-1 + 1) + 0;
        y = rand()%(Spielfeld::sizeY-1 + 1) + 0;
    } while (feld[x][y].getHasSnake());

    food.setXKoordinate(x);
    food.setYKoordinate(y);

    feld[food.getXKoordinate()][food.getYKoordinate()].setHasFood(true);
}
std::vector<std::vector< Coordinate>> &Spielfeld::getFeld()
 {
    return feld;
}

Coordinate &Spielfeld::getFood()
{
    return this->food;
}

Snake &Spielfeld::getSnake()
{
    return this->snake;
}

 unsigned long Spielfeld::getSizeX()
{
    return Spielfeld::sizeX;
}

void Spielfeld::setSizeX(unsigned long value)
{
    Spielfeld::sizeX = value;
}

 unsigned long Spielfeld::getSizeY()
{
    return Spielfeld::sizeY;
}

void Spielfeld::setSizeY(unsigned long value)
{
    Spielfeld::sizeY = value;
}

