#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include "Curser.ven"
#include "Title.ven"
void ArrayInit();void User();void shift();void dash();void stage();void procedure();
char name[]=" Venisoft | Adds Life To Your Machine: SNAKE",key=77,c;
int X=11,Y=31,i=19,j=0,speed=200,count=0,tempI,tempJ,change=1,ranI,ranJ,temp=77,score=0,b,x=0,y=0,p,q,QI[15],QJ[15];
void main()
{
  graph();
  initmouse();
  restrictmouse(0,0,638,478);
  showmouseptr();
  title(name);
  line(0,462,649,462);
  struct dostime_t t;_dos_gettime(&t);
  for(;t.second>0;t.second--)random(NULL);
  User();
  getch();
}
void User()
{
  ranI=random(20);
  ranJ=random(30);
  setcolor(RED);
  setfillstyle(1,BLUE);
  fillellipse(X+20*ranJ+2*ranJ,Y+20*ranI+2*ranI,10,10);
  do
  {
    while(!kbhit())
    {
      if(close(&change)==1)exit(0);
      if(key==72) if(i>0) --i;
		  else if(i==0)i=19;
      if(key==75) if(j>0) --j;
		  else if(j==0)j=28;
      if(key==77) if(j<28) ++j;
		  else if(j==28)j=0;
      if(key==80) if(i<19) ++i;
		  else if(i==19)i=0;
      if(ranI==i&&ranJ==j)
      {
	count++;score++;
	gotoxy(60,25);
	printf("Score : %d00",score);
	line(250,478,420,478);
	if(score%100==0){speed-=10;}
	if(count==15)
	{
	  count=0;
	  ArrayInit();
	  stage();
	}
	shift();
	QI[0]=ranI;
	QJ[0]=ranJ;
	S:
	  ranI=random(20);
	  ranJ=random(29);
	  for(q=0;q<count;q++)
	    if(ranI==QI[q]&&ranJ==QJ[q])goto S;
	setcolor(RED);
	setfillstyle(1,BLUE);
	fillellipse(X+20*ranJ+2*ranJ,Y+20*ranI+2*ranI,10,10);
      }
      dash();
      setcolor(WHITE);
      setfillstyle(1,6);
      procedure();
      delay(speed);
    }
    Y:
      key=getch();
      if(key==0) key=getch();
      if((temp==72&&key==80)||(temp==80&&key==72))goto Y;
      else if((temp==75&&key==77)||(temp==77&&key==75))goto Y;
      if(key==9)
      {
	 B:c=getch();
	   if(c==9){key=temp;}
	   else {goto B;}
      }
      temp=key;
  }while(1);
}
void stage()
{
  setcolor(14);setfillstyle(1,7);
  for(p=0;p<29;p++)
    for(q=19;q>=0;q--){fillellipse(X+20*p+2*p,Y+20*q+2*q,10,10);delay(5);}
  setcolor(BLACK);setfillstyle(1,BLACK);
  for(p=0;p<29;p++)
    for(q=0;q<20;q++){fillellipse(X+20*p+2*p,Y+20*q+2*q,10,10);delay(5);}
}
void procedure()
{
  setcolor(BLACK);
  setfillstyle(1,BLACK);
  tempI=QI[count];
  tempJ=QJ[count];
  fillellipse(X+20*tempJ+2*tempJ,Y+20*tempI+2*tempI,10,10);
  shift();
  setcolor(WHITE);
  setfillstyle(1,6);
  QI[0]=i;
  QJ[0]=j;
  fillellipse(X+20*j+2*j,Y+20*i+2*i,10,10);
}
void dash()
{
  for(p=1;p<=count;p++)if(i==QI[p]&&j==QJ[p]) exit(0);
}
void shift()
{
  for(p=0;p<count;p++)
  {
    QI[count-p]=QI[count-(p+1)];QJ[count-p]=QJ[count-(p+1)];
  }
}
void ArrayInit(){ for(p=0;p<20;p++){QI[p]=0;QJ[p]=0;} }
/****************************************************************************
*QI[count]  :Queue to store the "i"th index of Array[i][j]                  *
*QJ[count]  :Queue to store the "j"th index of Array[i][j]                  *
*count      :Used for the Queue management operations                       *
*p,q        :used in loops                                                  *
*i,j        :Positions of Array[i][j]                                       *
*X,Y        :Graphical Coordinates                                          *
*b,x,y      :Used for Mouse Motion                                          *
*tempI,tempJ:Used to store the previous values of QI[count],QJ[count]       *
*ranI,ranJ  :Stores random "i &j"th values                                  *
*change     :To highlight CLOSE button via "close(int *change);" function   *
*speed      :Used to set the game delay option                              *
*key        :Used to store which key is pressed                             *
*name[]     :Used to display title name via "title(char name[]);" function  *
*c          :Used to store and check the "pause" key                        *
*temp       :Used for temperary storage                                     *
****************************************************************************/