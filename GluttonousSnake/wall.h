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
    void setWall(int i,int j,char c);/*��������ķ��ţ��������º����ߵ�����*/
    char getWall(int i,int j);/*��ȡ����ķ��ţ����ж����Ƿ�Ƿ�*/
private:
    char gameArray[ROW][COL];
};


#endif // WALL_H_INCLUDED
