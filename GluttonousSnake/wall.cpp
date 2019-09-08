#include "wall.h"

void Wall::initWall()
{
    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<COL;j++)
        {
            if(i==0 || j==0 || i==ROW-1 || j==COL-1)
                gameArray[i][j] = '*';
            else
                gameArray[i][j] = ' ';
        }

    }
}
void Wall::draw()
{
    for(int i = 0;i<ROW;i++)
    {
        for(int j = 0;j<COL;j++)
        {
            cout<<gameArray[i][j]<<" ";
        }
        if(i==5)
            cout<<"a : left"<<endl;
        else if(i==6)
            cout<<"d : right"<<endl;
        else if(i==7)
            cout<<"w : up"<<endl;
        else if(i==8)
            cout<<"s : down"<<endl;
        else
            cout<<endl;
    }
}

void Wall::setWall(int i,int j,char c)
{
    gameArray[i][j] = c;
}
char Wall::getWall(int i,int j)
{
    return gameArray[i][j];
}
