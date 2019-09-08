#include <iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned int)time(0));
    Wall wall;
    Food food(wall);
    Snake snake(wall,food);
    wall.initWall();
    snake.initSnake();
    food.setFood();
//    snake.moveSnake('w');
//    snake.moveSnake('w');
//    snake.moveSnake('d');
    //snake.deletePoint();
    wall.draw();
    bool isDead = false;
    char preKey = NULL;
    while(!isDead)
    {
        char key = _getch();
        if(preKey == NULL && key == snake.LEFT)
            continue;
        if(((key == snake.LEFT) && (preKey == snake.RIGHT))||
            ((key == snake.RIGHT)&& (preKey == snake.LEFT))||
            ((key == snake.UP) && (preKey == snake.DOWN))||
            ((key == snake.DOWN) && (preKey == snake.UP)))
            key = preKey;
            do{
                if(key == snake.LEFT ||key == snake.RIGHT ||key == snake.UP ||key ==snake.DOWN)
                    {
                        if(snake.moveSnake(key))
                            {
                                system("cls");
                                wall.draw();
                                Sleep(200);
                            }
                        else
                            {
                                isDead = true;
                                break;
                            }
                    }
                else
                    {
                        key = preKey;
                    }
            }while(!_kbhit()); //没有键盘输入返回0
             preKey = key;
    }
    return 0;
}
