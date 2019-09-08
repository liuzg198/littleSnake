#include "food.h"

Food::Food(Wall& wallTemp):wall(wallTemp)
{
}
void Food::setFood()
{
    while(true)
    {
        foodX = rand()%(Wall::ROW-2)+1;
        foodY = rand()%(Wall::COL-2)+1;
        if(wall.getWall(foodX,foodY) == ' ')
            break;
        else
            foodX = rand()%(Wall::ROW-2)+1;
            foodY = rand()%(Wall::COL-2)+1;
    }
    wall.setWall(foodX,foodY,'#');
}
