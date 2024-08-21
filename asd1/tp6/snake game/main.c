#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int width=20,height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
bool gameOver;

void Setup()
{
    gameOver=false;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}

void Draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
        printf("#");
    printf("\n");

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                printf("#");
            if(i==y && j==x)
                printf("O");
            else if(i==fruitY && j==fruitX)
                printf("F");
            else
            {
                bool print=false;
                for(int k=0;k<nTail;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        printf("o");
                        print=true;
                    }
                }
                if(!print)
                    printf(" ");
            }

            if(j==width-1)
                printf("#");
        }
        printf("\n");
    }

    for(int i=0;i<width+2;i++)
        printf("#");
    printf("\nScore : %d\n",score);
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case 'x':
                gameOver=true;
                break;
        }
    }
}

void Logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<nTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(x)
    {
        case -1:
            x=width-1;
            break;
        case 20:
            x=0;
            break;
    }
    switch(y)
    {
        case -1:
            y=height-1;
            break;
        case 20:
            y=0;
            break;
    }
    for(int i=0;i<nTail;i++)
        if(tailX[i]==x && tailY[i]==y)
            gameOver=true;
    if(x==fruitX && y==fruitY)
    {
        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;
        nTail++;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    return 0;
}
