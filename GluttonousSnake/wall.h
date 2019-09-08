#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include <iostream>
using namespace std;
class Wall
{
public:
    enum
    {
        ROW = 26,
        COL = 26
    };
    void initWall();
    void draw();
    void setWall(int i,int j,char c);/*设置坐标的符号，用来更新后面蛇的生长*/
    char getWall(int i,int j);/*获取坐标的符号，来判断蛇是否非法*/
private:
    char gameArray[ROW][COL];
};


#endif // WALL_H_INCLUDED
