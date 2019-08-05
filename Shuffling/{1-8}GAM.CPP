#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include"curser.ven"
#include"title.ven"
#include"close.ven"
void graph();
void table();
void print();
void check();
int DEMO[4][4],CHECK[15],CHECKj=0,i,j,k,iz,jz,temp,b=0,x=100,y=150,change;
float ti;
char f;
time_t fir,sec;
void main()
{
   struct dostime_t t;

   fir=time(NULL);
   graph();
   initmouse();
   restrictmouse(1,1,638,478);
   showmouseptr();
   table();
   _dos_gettime(&t);
   for(;t.second>0;t.second--)random(NULL);
   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
      {
	S:
	  temp=random(16);
	  for(k=0;k<CHECKj;k++)
	     if(temp==CHECK[k]){goto S;}
	  CHECK[CHECKj]=temp;
	  DEMO[i][j]=temp;CHECKj++;
      }
      do
      {
	 print();
	 title(" Venisoft:Adds Life To Your Machine : Shuffling");
	 gotoxy(3,18);printf("Enter DIGIT to proceed:");
	 while(!kbhit()||b==2)
	 {
	   close(&change);
	   getmousestatus(&b,&x,&y);
	   if(b==1&&x>=617&&x<=638&&y>=1&&y<=19)
	   {
	     K:
	       f=b2tab();
	       if(f=='Y'||f=='y'){cleardevice();gotoxy(27,19);printf("Thank you for your play");delay(2000);exit(0);}
	       else if(f=='N'||f=='n'){setfillstyle(1,BLACK);bar(200,300,260,320);bar(400,300,460,320);}
	       else goto K;
	   }
	 }
	 check();
      }while(1);
}
void table()
{
   setcolor(GREEN);
   rectangle(20,50,210,240);
   setcolor(8);
   line(20,95,210,95);
   line(20,140,210,140);
   line(20,190,210,190);
   line(65,50,65,240);
   line(115,50,115,240);
   line(165,50,165,240);
}
void check()
{
   gotoxy(3,18);printf("Enter DIGIT to proceed:");
   scanf("%d",&temp);
   for(i=0;i<4;i++)for(j=0;j<4;j++)if(DEMO[i][j]==0){iz=i;jz=j;}
   for(i=0;i<4;i++)
     for(j=0;j<4;j++)
       if(DEMO[i][j]==temp)
       {
	  if(i==iz||j==jz)
	  {
	     if(iz-i==1||iz-i==-1){temp=DEMO[i][j];DEMO[i][j]=DEMO[iz][jz];DEMO[iz][jz]=temp;}
	     if(jz-j==1||jz-j==-1){temp=DEMO[i][j];DEMO[i][j]=DEMO[iz][jz];DEMO[iz][jz]=temp;}
	  }
       }
   temp=0;
   int win=0;
   for(i=0;i<4;i++)
     for(j=0;j<4;j++)
     {
	win++;
	if(DEMO[i][j]==win)temp++;
     }
   if(temp>=15)
   {
     print();
     gotoxy(3,18);printf("                                       ");
     gotoxy(27,19);printf("You   WIN   Shuffling");getch();exit(0);
   }
   gotoxy(3,18);printf("Enter DIGIT to proceed:                ");
   gotoxy(1,19);printf("  \n   \n   \n   ");
   for(temp=21;temp<29;temp++){gotoxy(1,temp);printf("        ");}
}
void print()
{
   for(i=0;i<4;i++)
   {
      for(j=0;j<4;j++)
      {
	gotoxy(5+j*6,5+i*3);
	if(DEMO[i][j]<=9)
	  if(DEMO[i][j]==0) printf("   ");
	  else  printf(" %d",DEMO[i][j]);
	else printf("%d",DEMO[i][j]);
      }
   }
}
