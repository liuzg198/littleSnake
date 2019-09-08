#include "snake.h"

Snake::Snake(Wall& tempWall,Food& tempFood):wall(tempWall),food(tempFood)
{
    pHead = nullptr;
}
void Snake::initSnake()
{
    destoryPoint();
    addPoint(5,6);
    addPoint(5,7);
    addPoint(5,8);
}
void Snake::destoryPoint()
{
    Point* pTemp;
    while(pHead != nullptr)
    {
        pTemp = pHead->next;
        delete pHead;
        pHead = pTemp;
    }
}

void Snake::addPoint(int x,int y)
{
    Point* point = new Point;
    point->x = x;
    point->y = y;
    if(pHead !=nullptr)
    {
        wall.setWall(pHead->x,pHead->y,'=');
    }
    point->next = pHead;
    pHead = point;
    wall.setWall(x,y,'@');
}
void Snake::deletePoint()
{
    if(pHead == nullptr || pHead->next ==nullptr)
        return;
    Point* pTemp = pHead->next;
    Point* pPre = pHead;
    while(pTemp->next != nullptr)
    {
        pTemp = pTemp->next;
        pPre = pPre->next;
    }
    wall.setWall(pTemp->x,pTemp->y,' ');
    delete pTemp;
    pTemp = nullptr;
    pPre->next = nullptr;
}
bool Snake::moveSnake(char key)
{
    int x = pHead->x;
    int y = pHead->y;
    switch(key)
    {
    case UP:
        --x;
        break;
    case DOWN:
        ++x;
        break;
    case LEFT:
        --y;
        break;
    case RIGHT:
        ++y;
        break;
    default:
        break;
    }
    if(wall.getWall(x,y) =='*'||wall.getWall(x,y) == '=')
    {
        cout<<"GAME OVER!!!"<<endl;
        return false;
    }
    //³Ôµ½Ê³Îï
    if(wall.getWall(x,y)=='#')
    {
        addPoint(x,y);
        food.setFood();
    }
    else
    {
        addPoint(x,y);
        deletePoint();
    }
    return true;

}
