//solo snake game version
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define length 100
#define width 20
#define max_s 100
int adx=1,ady=0;
typedef struct {
int x;
int y;
}xsnake;
xsnake food;
xsnake asnake[max_s];
int score=0;
int size=3;
void board(void);
void move(void);
void gameover(void);
void gen_food(void);


int main() {
    for(int k=0;k<3;k++)
    {
    asnake[k].x=length/2-k;
    asnake[k].y=width/2;
    }
    gen_food();
    while(1)
 {
     board();
     move();
   Sleep(0.1);
 }




    return 0;
}
void board(void)
{

    system("cls");
   int i,j;
   for(i=0;i<=width;i++)
   {
        for(j=0;j<=length;j++)
            {
        if(i==0 || i==width || j==0 || j==length)
                 printf("#");
      else
      {
          int isbody=0;

              for(int k=0;k<size;k++)
      if(j==asnake[k].x && i==asnake[k].y )
      {
           printf("*");
           isbody=1;
           break;
      }
         if(!isbody)
          if(j==food.x && i==food.y)
        printf("o");
        else
        printf(" ");

      }

            }
    printf("\n");
   }
   printf("\tscore %d",score*10);
}
void move(void)
{
    char ch;

for(int k=size-1;k>0;k--)
    asnake[k]=asnake[k-1];

    asnake[0].x+=adx;
    asnake[0].y+=ady;
    if(asnake[0].x==length || asnake[0].y==width || asnake[0].x==0 || asnake[0].y==0)
      gameover();
      for(int k=1;k<size;k++)
      if(asnake[0].x==asnake[k].x && asnake[0].y==asnake[k].y )
      gameover();
       if (asnake[0].x == food.x && asnake[0].y == food.y) {
        gen_food();
        score++;
        size++;
    }


         if(_kbhit())
    {
        ch=getch();
    switch(ch)
    {
    case 'z': //up
        if(ady!=1){ ady=-1; adx=0;} break;

    case 's'://down
         if(ady!=-1){ ady=1;  adx=0; } break;
    case 'd'://right
        if(adx!=-1){adx=1;  ady=0; }   break;
    case 'q'://left
         if(adx!=1){adx=-1; ady=0;}  break;
    case 'e':
     ady=-1; adx=1; break;
    case 'a':
      ady=-1; adx=-1; break;
    case 'w':
        ady=1; adx=-1; break;
    case 'c':
        ady=1; adx=1; break;
    case 'n':
        {
            for(int k=0;k<size;k++)
            asnake[k].x+=15;
            adx=1;
            break;
        }
    }

    }

}
void gameover(void)
{

      system("cls");
    printf("\n\n===== GAME OVER! =====\n");
    printf("/your final score is %d\\\n\n",score*10);
   exit(0);

 }
void gen_food(void)
{
int notfood;
    do
    {
       notfood=1;
       food.x=rand()%(length-1)+1;
       food.y=rand()%(width-1)+1;
      for(int k=0;k<size;k++)
        if(food.x==asnake[k].x && food.y==asnake[k].y)
      {
          notfood=0;
          break;
      }

    }while(!notfood);

}

