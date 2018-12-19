#ifndef SNAKE_H
#define SNAKE_H
#include <queue>
#include <coordinate.h>

class Snake
{
public:
    Snake();
    std::queue<Coordinate> &getSnake();
    void addNewPosition(int x, int y);
    Coordinate deleteLastPosition();

private:
    std::queue<Coordinate> posSnake;
};

#endif // SNAKE_H
