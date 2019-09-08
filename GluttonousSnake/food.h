#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include "wall.h"
class Food
{
public:
    Food(Wall& wall);
    void setFood();
    int foodX;
    int foodY;
    Wall& wall;
};


#endif // FOOD_H_INCLUDED
