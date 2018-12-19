#include "snake.h"

Snake::Snake()
{
   posSnake = *(new std::queue<Coordinate>);
  // posSnake.push(*(new Coordinate(0,0,false,true)));
}

std::queue<Coordinate>& Snake::getSnake()
{
    return this->posSnake;
}

void Snake::addNewPosition(int x, int y)
{
    this->posSnake.push(*(new Coordinate(x,y,false,true)));
}

Coordinate Snake::deleteLastPosition()
{
    Coordinate temp = posSnake.front();
    this->posSnake.pop();
    return temp;
}
