#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "wall.h"
#include "food.h"
class Snake
{
  public:
      enum {
        UP='w',DOWN='s',LEFT='a',RIGHT='d'
      };
      Snake(Wall& tempWall,Food& tempFood);
      struct Point
      {
          int x;
          int y;
          Point* next;
      };
      void initSnake();
      //销毁节点
      void destoryPoint();
      // 添加节点
      void addPoint(int x,int y);
      void deletePoint();
      bool moveSnake(char key);
      Point* pHead;
      Wall& wall;
      Food& food;
};

#endif // SNAKE_H_INCLUDED
