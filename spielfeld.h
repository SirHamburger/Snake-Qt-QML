#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <coordinate.h>
#include <vector>
#include <snake.h>
class Spielfeld
{
public:
    Spielfeld();
    void generateFood();
    std::vector<std::vector< Coordinate>> &getFeld();
    Coordinate &getFood();
    Snake &getSnake();

   static unsigned long getSizeX() ;
    static void setSizeX(unsigned long value);

    static unsigned long getSizeY() ;
    static void setSizeY(unsigned long value);

    Coordinate getPoop() const;
    void setPoop(const Coordinate &value);

private:
    std::vector<std::vector< Coordinate>> feld;
    Snake snake;
   Coordinate food;
   static unsigned long sizeX;
   static unsigned long sizeY;
};


#endif // SPIELFELD_H
