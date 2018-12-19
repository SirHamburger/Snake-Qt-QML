#ifndef COORDINATE_H
#define COORDINATE_H


class Coordinate
{
public:
    Coordinate();
    Coordinate(int x, int y, bool hasFood, bool hasSnake);
    void setXKoordinate(int x);
    void setYKoordinate(int y);
    int getXKoordinate();
    int getYKoordinate();
    //bool operator==(const Coordinate &a, const Coordinate &b);
    bool getHasFood() const;
    void setHasFood(bool value);

    bool getHasSnake() const;
    void setHasSnake(bool value);

    bool getHasPoop() const;
    void setHasPoop(bool value);

private:
    int xKoordinate;
    int yKoordinate;
    bool hasFood;
    bool hasSnake;
    bool hasPoop;
};

#endif // COORDINATE_H
