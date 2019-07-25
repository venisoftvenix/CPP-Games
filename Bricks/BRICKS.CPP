#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include"V2vsS2.VEN"
void graph();void L();void I();void T();void N();void O();void Plus();
void venisoft();void movements();void ASSIGN(int Z);void DELETE_ROW();void REPRINT();
void venix(int X,int Y,int C);void venisoft();void Rotate();
void g();void Boom();
int i,j;
int DEMO[20][10],SCORE=0;
int X=91,Y=11,SPEED=100,SELECT,V,v=1,Fr=0,rem,count=0,P,Q,temp_X,temp_Y,commet=5;
int Dir_L=1,Dir_I=1,Dir_T=1,Dir_N=1,Dir_O=1,Dir_Plus=1;
int loop_count=0;
void main()
{
    graph();venisoft();
    X=91;Y=11;
    struct dostime_t t;
    _dos_gettime(&t);
   for(;t.second>0;t.second--)random(NULL);
    for(i=0;i<20;i++)
       for(j=0;j<10;j++)
	  DEMO[i][j]=0;
    i=0;j=4;
    gotoxy(27,1); printf("-> HOW TO PLAY:");
    gotoxy(30,2); printf("You have to arrange the falling objects,such that");
    gotoxy(30,3); printf("as if any ROW is filled then that ROW is deleted");
    gotoxy(30,4); printf("and your SCORE increases by 100 Points.If the ");
    gotoxy(30,5); printf("arrangement reaches TOP border your game ends.");
    gotoxy(27,7); printf("-> KEYS:");
    gotoxy(30,8); printf("Left         -        LEFT ARROW");
    gotoxy(30,9); printf("Right        -        RIGHT ARROW");
    gotoxy(30,10);printf("Rotate       -        SPACE");
    gotoxy(30,11);printf("Conform      -        DOWN ARROW");
    gotoxy(30,12);printf("Pause        -        TAB");
    gotoxy(30,13);printf("Quit         -        ESC");
    gotoxy(30,22);printf("Created by Venigandla Venkatesh");
    gotoxy(30,25);printf("SCORE : %d00",SCORE);
    gotoxy(5,5);printf("ARE YOU READY");
    gotoxy(5,6);printf(" Press ENTER");
    setcolor(14);setfillstyle(1,GREEN);rectangle(0,0,629,478);rectangle(0,0,629,400);rectangle(0,0,201,400);
    getch();
    gotoxy(5,5);printf("             ");
    gotoxy(5,6);printf("            ");
    do
    {
       SELECT=random(6);
       switch(SELECT)
       {
	 case 0:L();   break;
	 case 1:I();   break;
	 case 2:T();   break;
	 case 3:N();   break;
	 case 4:O();   break;
	 case 5:Plus();break;
       }
       movements();
       for(int ii=0;ii<10;ii++)if(DEMO[0][ii]==1){cleardevice();gotoxy(10,15);printf("Thank you for your play. Your SCORE is %d00. Press ENTER.",SCORE);char YN=getch();if(YN=='\r'||YN=='\n')exit(0);}
       setcolor(14);setfillstyle(1,GREEN);
       switch(SELECT)
       {
	 case 0:L();   break;
	 case 1:I();   break;
	 case 2:T();   break;
	 case 3:N();   break;
	 case 4:O();   break;
	 case 5:Plus();break;
       }
       sound(2000);delay(200);nosound();
       ASSIGN(1);
       //Checks Line fill
       temp_X=X;temp_Y=Y;
       loop_count=0;
       g();
       X=temp_X;Y=temp_Y;
       X=91;i=0;j=4;DEMO[i][j]=0;Y=11;
    }while(1);
}
void g()
{
    loop_count++;
    for(P=19;P>=0;P--)
    {
      count=0;
      if(DEMO[P][3]==1&&DEMO[P][5]==1&&DEMO[P][8]==1)
	for(Q=0;Q<10;Q++)
	{
	   if(DEMO[P][Q]==1)
	   {
	  count++;
	  if(count==10)
	  {
	    DELETE_ROW();
	    sound(1000);delay(100);nosound();
	    SCORE++;
	    REPRINT();
	    if(loop_count<=20)
	      g();
	  }
	   }
	   else Q=12;
	}
    }
}
void REPRINT()
{
    cleardevice();
    rectangle(0,0,629,479);rectangle(0,0,201,400);rectangle(0,0,629,400);
    setcolor(14);setfillstyle(1,GREEN);
    for(int A=19,Y=391;A>=0;A--,Y-=20)
    {
       for(int B=9,X=191;B>=0;B--,X-=20)
       {
	  if(DEMO[A][B]==1)
	    bar(X-9,Y-9,X+9,Y+9);
       }
    }
}
void DELETE_ROW()
{
    for(;P>0;P--)
       for(Q=0;Q<10;Q++)
	  DEMO[P][Q]=DEMO[P-1][Q];
    for(Q=0;Q<10;Q++)DEMO[0][Q]=0;
}
void ASSIGN(int Z)
{
       switch(SELECT)
       {
	    case 0:
	    {
			if(Dir_L==1){DEMO[i][j]=Z;DEMO[i+1][j]=Z;DEMO[i+2][j]=Z;DEMO[i+2][j+1]=Z;      }
		   else if(Dir_L==2){DEMO[i+1][j]=Z;DEMO[i+1][j+1]=Z;DEMO[i+1][j+2]=Z;DEMO[i][j+2]=Z;  }
		   else if(Dir_L==3){DEMO[i][j]=Z;DEMO[i][j+1]=Z;DEMO[i+1][j+1]=Z;DEMO[i+2][j+1]=Z;    }
		   else if(Dir_L==4){DEMO[i][j]=Z;DEMO[i+1][j]=Z;DEMO[i][j+1]=Z;DEMO[i][j+2]=Z;        }
		   break;
	    }
	    case 1:
	    {
			if(Dir_I==1){DEMO[i][j]=Z;DEMO[i][j+1]=Z;DEMO[i][j+2]=Z;DEMO[i][j+3]=Z;      }
		   else if(Dir_I==2){DEMO[i][j]=Z;DEMO[i+1][j]=Z;DEMO[i+2][j]=Z;DEMO[i+3][j]=Z;      }
		   break;
	    }
	    case 2:
	    {
			if(Dir_T==1){DEMO[i][j]=Z;DEMO[i][j+1]=Z;DEMO[i][j+2]=Z;DEMO[i+1][j+1]=Z;      }
		   else if(Dir_T==2){DEMO[i][j]=Z;DEMO[i+1][j]=Z;DEMO[i+2][j]=Z;DEMO[i+1][j+1]=Z;      }
		   else if(Dir_T==3){DEMO[i][j+1]=Z;DEMO[i+1][j]=Z;DEMO[i+1][j+1]=Z;DEMO[i+1][j+2]=Z;  }
		   else if(Dir_T==4){DEMO[i][j+1]=Z;DEMO[i+1][j+1]=Z;DEMO[i+2][j+1]=Z;DEMO[i+1][j]=Z;      }
		   break;
	    }
	    case 3:
	    {
			if(Dir_N==1){DEMO[i][j+1]=Z;DEMO[i+1][j]=Z;DEMO[i+1][j+1]=Z;DEMO[i+2][j]=Z;      }
		   else if(Dir_N==2){DEMO[i][j]=Z;DEMO[i][j+1]=Z;DEMO[i+1][j+1]=Z;DEMO[i+1][j+2]=Z;      }
		   break;
	    }
	    case 4:     DEMO[i][j]=Z;DEMO[i+1][j]=Z;DEMO[i][j+1]=Z;DEMO[i+1][j+1]=Z;      break;
	    case 5:     DEMO[i][j+1]=Z;DEMO[i+1][j]=Z;DEMO[i+1][j+1]=Z;DEMO[i+1][j+2]=Z;DEMO[i+2][j+1]=Z;break;
       }
}
void Boom()
{
	  rem=Y%10;
	  if(rem==1)
	  {
	     rem=Y/10;rem=rem%10;rem=rem%2;
	     if(rem==0)
	     {
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;return;}if(Fr==5)Fr=1;
	       setcolor(14);setfillstyle(1,GREEN);
	       switch(SELECT)
	       {
		 case 0:L();   break;
		 case 1:I();   break;
		 case 2:T();   break;
		 case 3:N();   break;
		 case 4:O();   break;
		 case 5:Plus();break;
	       }
	       delay(50);
	       setcolor(BLACK);setfillstyle(1,BLACK);
	       switch(SELECT)
	       {
		 case 0:L();   break;
		 case 1:I();   break;
		 case 2:T();   break;
		 case 3:N();   break;
		 case 4:O();   break;
		 case 5:Plus();break;
	       }
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;return;}if(Fr==5)Fr=1;
	     }
	     else if(rem==1)return;
	  }
	  else if(rem==6)
	  {
	     rem=Y/10;rem=rem%10;rem=rem%2;
	     if(rem==0)
	     {
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;return;}if(Fr==5)Fr=1;
	     }
	     if(rem==1)
	     {
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;return;}if(Fr==5)Fr=1;
	       setcolor(14);setfillstyle(1,GREEN);
	       switch(SELECT)
	       {
		 case 0:L();   break;
		 case 1:I();   break;
		 case 2:T();   break;
		 case 3:N();   break;
		 case 4:O();   break;
		 case 5:Plus();break;
	       }
	       delay(50);
	       setcolor(BLACK);setfillstyle(1,BLACK);
	       switch(SELECT)
	       {
		 case 0:L();   break;
		 case 1:I();   break;
		 case 2:T();   break;
		 case 3:N();   break;
		 case 4:O();   break;
		 case 5:Plus();break;
	       }
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;return;}if(Fr==5)Fr=1;
	       setcolor(14);setfillstyle(1,GREEN);
	       switch(SELECT)
	       {
		 case 0:L();   break;
		 case 1:I();   break;
		 case 2:T();   break;
		 case 3:N();   break;
		 case 4:O();   break;
		 case 5:Plus();break;
	       }
	       delay(50);
	       setcolor(BLACK);setfillstyle(1,BLACK);
	       switch(SELECT)
	       {
		 case 0:L();   break;
		 case 1:I();   break;
		 case 2:T();   break;
		 case 3:N();   break;
		 case 4:O();   break;
		 case 5:Plus();break;
	       }
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;return;}if(Fr==5)Fr=1;
	     }
	  }
}
void movements()
{
    SPEED=100;
    gotoxy(27,1); printf("-> HOW TO PLAY:");
    gotoxy(30,2); printf("You have to arrange the falling objects,such that");
    gotoxy(30,3); printf("as if any ROW is filled then that ROW is deleted");
    gotoxy(30,4); printf("and your SCORE increases by 100 Points.If the ");
    gotoxy(30,5); printf("arrangement reaches TOP border your game ends.");
    gotoxy(27,7); printf("-> KEYS:");
    gotoxy(30,8); printf("Left         -        LEFT ARROW");
    gotoxy(30,9); printf("Right        -        RIGHT ARROW");
    gotoxy(30,10);printf("Rotate       -        SPACE");
    gotoxy(30,11);printf("Conform      -        DOWN ARROW");
    gotoxy(30,12);printf("Pause        -        TAB");
    gotoxy(30,13);printf("Quit         -        ESC");
    gotoxy(30,22);printf("Created by Venigandla Venkatesh");
    gotoxy(30,25);printf("SCORE : %d00",SCORE);
    do
    {
       setcolor(14);setfillstyle(1,GREEN);
       rectangle(0,0,629,478);rectangle(0,0,201,400);rectangle(0,0,629,400);
       while(!kbhit())
       {
	  delay(SPEED);
	  setcolor(BLACK);setfillstyle(1,BLACK);
	  switch(SELECT)
	  {
	    case 0:L();   break;
	    case 1:I();   break;
	    case 2:T();   break;
	    case 3:N();   break;
	    case 4:O();   break;
	    case 5:Plus();break;
	  }
	  ASSIGN(0);
	  switch(SELECT)
	  {
	    case 0:
	    {
			if(Dir_L==1&&Y>339+10) return;
		   else if(Dir_L==2&&Y>359+10) return;
		   else if(Dir_L==3&&Y>339+10) return;
		   else if(Dir_L==4&&Y>359+10) return;
		   break;
	    }
	    case 1:
	    {
			if(Dir_I==1&&Y>379+10) return;
		   else if(Dir_I==2&&Y>319+10) return;
		   break;
	    }
	    case 2:
	    {
			if(Dir_T==1&&Y>359+10) return;
		   else if(Dir_T==2&&Y>339+10) return;
		   else if(Dir_T==3&&Y>359+10) return;
		   else if(Dir_T==4&&Y>339+10) return;
		   break;
	    }
	    case 3:
	    {
			if(Dir_N==1&&Y>339+10) return;
		   else if(Dir_N==2&&Y>359+10) return;
		   break;
	    }
	    case 4:     if(Y>359+10) return;break;
	    case 5:     if(Y>339+10) return;break;
	  }
	  switch(SELECT)
	  {
	    case 0:
	    {
			if(Dir_L==1)if(DEMO[i+3][j]==0&&DEMO[i+3][j+1]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                       else return;
		   else if(Dir_L==2)if(DEMO[i+2][j]==0&&DEMO[i+2][j+1]==0&&DEMO[i+2][j+2]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                    else return;
		   else if(Dir_L==3)if(DEMO[i+1][j]==0&&DEMO[i+3][j+1]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                         else return;
		   else if(Dir_L==4)if(DEMO[i+2][j]==0&&DEMO[i+1][j+1]==0&&DEMO[i+1][j+2]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                    else return;
		   break;
	    }
	    case 1:
	    {
			if(Dir_I==1)if(DEMO[i+1][j]==0&&DEMO[i+1][j+1]==0&&DEMO[i+1][j+2]==0&&DEMO[i+1][j+3]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;} else return;
		   else if(Dir_I==2)if(DEMO[i+4][j]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                                          else return;
		   break;
	    }
	    case 2:
	    {
			if(Dir_T==1)if(DEMO[i+1][j]==0&&DEMO[i+2][j+1]==0&&DEMO[i+1][j+2]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                    else return;
		   else if(Dir_T==2)if(DEMO[i+3][j]==0&&DEMO[i+2][j+1]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                       else return;
		   else if(Dir_T==3)if(DEMO[i+2][j]==0&&DEMO[i+2][j+1]==0&&DEMO[i+2][j+2]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                    else return;
		   else if(Dir_T==4)if(DEMO[i+2][j]==0&&DEMO[i+3][j+1]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                       else return;
		   break;
	    }
	    case 3:
	    {
			if(Dir_N==1)if(DEMO[i+3][j]==0&&DEMO[i+2][j+1]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                       else return;
		   else if(Dir_N==2)if(DEMO[i+1][j]==0&&DEMO[i+2][j+1]==0&&DEMO[i+2][j+2]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                    else return;
		   break;
	    }
	    case 4:   if(DEMO[i+2][j]==0&&DEMO[i+2][j+1]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                                     else return;break;
	    case 5:   if(DEMO[i+2][j]==0&&DEMO[i+3][j+1]==0&&DEMO[i+2][j+2]==0){Y=Y+5;Fr++;if(Fr==4)DEMO[++i][j]=0;if(Fr==5)Fr=1;}                                  else return;break;
	  }
	  switch(SELECT)
	  {
	    case 0:
	    {
			if(Dir_L==1&&Y>339+10) return;
		   else if(Dir_L==2&&Y>359+10) return;
		   else if(Dir_L==3&&Y>339+10) return;
		   else if(Dir_L==4&&Y>359+10) return;
		   break;
	    }
	    case 1:
	    {
			if(Dir_I==1&&Y>379+10) return;
		   else if(Dir_I==2&&Y>319+10) return;
		   break;
	    }
	    case 2:
	    {
			if(Dir_T==1&&Y>359+10) return;
		   else if(Dir_T==2&&Y>339+10) return;
		   else if(Dir_T==3&&Y>359+10) return;
		   else if(Dir_T==4&&Y>339+10) return;
		   break;
	    }
	    case 3:
	    {
			if(Dir_N==1&&Y>339+10) return;
		   else if(Dir_N==2&&Y>359+10) return;
		   break;
	    }
	    case 4:     if(Y>359+10) return;break;
	    case 5:     if(Y>339+10) return;break;
	  }
	  setcolor(14);setfillstyle(1,GREEN);
	  switch(SELECT)
	  {
	    case 0:L();   break;
	    case 1:I();   break;
	    case 2:T();   break;
	    case 3:N();   break;
	    case 4:O();   break;
	    case 5:Plus();break;
	  }
	  ASSIGN(1);
	  /*
	  for(int ii=0;ii<20;ii++)
	  {
	     for(int jj=0;jj<10;jj++)
	     {
		gotoxy(jj+50,ii+1);printf("%d",DEMO[ii][jj]);
	     }
	  }
	  */
	  ASSIGN(0);
       }
       V=getch();
       if(V==0)
       V=getch();
       if(V==9&&v==0){v=1;V=5;}
       setcolor(BLACK);setfillstyle(1,BLACK);
       switch(SELECT)
       {
	 case 0:L();   break;
	 case 1:I();   break;
	 case 2:T();   break;
	 case 3:N();   break;
	 case 4:O();   break;
	 case 5:Plus();break;
       }
       if(V==75)  //Left
       {
	  ASSIGN(0);
	  //Boom ~~~|
	  Boom();
	  //Boom ...|
	  switch(SELECT)
	  {
	    case 0:
	    {
			if(Dir_L==1&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j-1]==0&&DEMO[i+2][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_L==2&&X>=31){if(DEMO[i+1][j-1]==0&&DEMO[i][j+1]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_L==3&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j]==0&&DEMO[i+2][j]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_L==4&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   break;
	    }
	    case 1:
	    {
			if(Dir_I==1&&X>=31){if(DEMO[i][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_I==2&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j-1]==0&&DEMO[i+2][j-1]==0&&DEMO[i+3][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   break;
	    }
	    case 2:
	    {
			if(Dir_T==1&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_T==2&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j-1]==0&&DEMO[i+2][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_T==3&&X>=31){if(DEMO[i][j]==0&&DEMO[i+1][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_T==4&&X>=31){if(DEMO[i][j]==0&&DEMO[i+1][j-1]==0&&DEMO[i+2][j]==0){X=X-20;DEMO[i][--j]=0;}}
		   break;
	    }
	    case 3:
	    {
			if(Dir_N==1&&X>=31){if(DEMO[i][j]==0&&DEMO[i+1][j-1]==0&&DEMO[i+2][j-1]==0){X=X-20;DEMO[i][--j]=0;}}
		   else if(Dir_N==2&&X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j]==0){X=X-20;DEMO[i][--j]=0;}}
		   break;
	    }
	    case 4:   if(X>=31){if(DEMO[i][j-1]==0&&DEMO[i+1][j-1]==0){X=X-20;DEMO[i][--j]=0;}}break;
	    case 5:   if(X>=31){if(DEMO[i][j]==0&&DEMO[i+1][j-1]==0&&DEMO[i+2][j]==0){X=X-20;DEMO[i][--j]=0;}}break;
	  }
       }
       if(V==77)  //Right
       {
	  ASSIGN(0);
	  //Boom ~~~|
	  Boom();
	  //Boom ...|
	  switch(SELECT)
	  {
	    case 0:
	    {
			if(Dir_L==1&&X<169){if(DEMO[i][j+1]==0&&DEMO[i+1][j+1]==0&&DEMO[i+2][j+2]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_L==2&&X<149){if(DEMO[i][j+3]==0&&DEMO[i+1][j+3]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_L==3&&X<169){if(DEMO[i][j+2]==0&&DEMO[i+1][j+2]==0&&DEMO[i+2][j+2]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_L==4&&X<149){if(DEMO[i][j+3]==0&&DEMO[i+1][j+1]==0){X=X+20; DEMO[i][++j]=0;}}
		   break;
	    }
	    case 1:
	    {
			if(Dir_I==1&&X<129){if(DEMO[i][j+4]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_I==2&&X<189){if(DEMO[i][j+1]==0&&DEMO[i+1][j+1]==0&&DEMO[i+2][j+1]==0&&DEMO[i+3][j+1]==0){X=X+20; DEMO[i][++j]=0;}}
		   break;
	    }
	    case 2:
	    {
			if(Dir_T==1&&X<149){if(DEMO[i][j+3]==0&&DEMO[i+1][j+2]==0&&DEMO[i+2][j+2]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_T==2&&X<169){if(DEMO[i][j+1]==0&&DEMO[i+1][j+2]==0&&DEMO[i+2][j+1]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_T==3&&X<149){if(DEMO[i][j+2]==0&&DEMO[i+1][j+3]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_T==4&&X<169){if(DEMO[i][j+2]==0&&DEMO[i+1][j+2]==0&&DEMO[i+2][j+2]==0){X=X+20; DEMO[i][++j]=0;}}
		   break;
	    }
	    case 3:
	    {
			if(Dir_N==1&&X<169){if(DEMO[i][j+2]==0&&DEMO[i+1][j+2]==0&&DEMO[i+2][j+1]==0){X=X+20; DEMO[i][++j]=0;}}
		   else if(Dir_N==2&&X<149){if(DEMO[i][j+2]==0&&DEMO[i+1][j+3]==0){X=X+20; DEMO[i][++j]=0;}}
		   break;
	    }
	    case 4:     if(X<169){if(DEMO[i][j+2]==0&&DEMO[i+1][j+2]==0){X=X+20; DEMO[i][++j]=0;}} break;
	    case 5:     if(X<149){if(DEMO[i][j+2]==0&&DEMO[i+1][j+3]==0&&DEMO[i+2][j+2]==0&&DEMO[i+3][j-1]==0){X=X+20; DEMO[i][++j]=0;}} break;
	  }
       }
       if(V==80)
       {
	  SPEED=10;
	  V=4;
       }
       if(V==32)
       {
	  ASSIGN(0);
	  //////////////////////////////////
	  int temp_Y=Y,temp_i=i,temp_j=j,temp_Fr=Fr;
	  rem=Y%10;
	  if(rem==1)
	  {
	     rem=Y/10;rem=rem%10;rem=rem%2;
	     if(rem==0)
	     {
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;}if(Fr==5)Fr=1;
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;}if(Fr==5)Fr=1;
	     }
	     else if(rem==1){}
	  }
	  else if(rem==6)
	  {
	     rem=Y/10;rem=rem%10;rem=rem%2;
	     if(rem==0)
	     {
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;}if(Fr==5)Fr=1;
	     }
	     if(rem==1)
	     {
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;}if(Fr==5)Fr=1;
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;}if(Fr==5)Fr=1;
	       Y=Y+5;Fr++;if(Fr==4){DEMO[++i][j]=0;}if(Fr==5)Fr=1;
	     }
	  }
	  ///////////////////////////////////////
	  //Boom ~~~|
	  switch(SELECT)
	  {
	     case 0:
	     {
			if(Dir_L==1){if(DEMO[i][j+2]==0&&DEMO[i+1][j]==0&&DEMO[i+1][j+1]==0&&DEMO[i+1][j+2]==0){Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_L==2){if(DEMO[i][j]==0&&DEMO[i][j+1]==0&&DEMO[i+1][j+1]==0&&DEMO[i+2][j+1]==0)  {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_L==3){if(DEMO[i][j]==0&&DEMO[i][j+1]==0&&DEMO[i][j+2]==0&&DEMO[i+1][j]==0)      {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_L==4){if(DEMO[i][j]==0&&DEMO[i+1][j]==0&&DEMO[i+2][j]==0&&DEMO[i+2][j+1]==0)    {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   break;
	     }
	     case 1:
	     {
			if(Dir_I==1){if(DEMO[i][j]==0&&DEMO[i+1][j]==0&&DEMO[i+2][j]==0&&DEMO[i+3][j]==0)      {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_I==2){if(DEMO[i][j]==0&&DEMO[i][j+1]==0&&DEMO[i][j+2]==0&&DEMO[i][j+3]==0)      {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   break;
	     }
	     case 2:
	     {
			if(Dir_T==1){if(DEMO[i][j]==0&&DEMO[i+1][j]==0&&DEMO[i+2][j]==0&&DEMO[i+1][j+1]==0)    {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_T==2){if(DEMO[i+1][j]==0&&DEMO[i+1][j+1]==0&&DEMO[i+1][j+2]==0&&DEMO[i][j+1]==0){Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_T==3){if(DEMO[i][j+1]==0&&DEMO[i+1][j+1]==0&&DEMO[i+2][j+1]==0&&DEMO[i+1][j]==0){Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_T==4){if(DEMO[i][j]==0&&DEMO[i][j+1]==0&&DEMO[i][j+2]==0&&DEMO[i+1][j+1]==0)    {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   break;
	     }
	     case 3:
	     {
			if(Dir_N==1){if(DEMO[i][j]==0&&DEMO[i][j+1]==0&&DEMO[i+1][j+1]==0&&DEMO[i+1][j+2]==0)  {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   else if(Dir_N==2){if(DEMO[i][j+1]==0&&DEMO[i+1][j]==0&&DEMO[i+1][j+1]==0&&DEMO[i+2][j]==0)  {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}
		   break;
	     }
	     case 4:    if(1){if(DEMO[i][j]==0&&DEMO[i][j+1]==0&&DEMO[i+1][j]==0&&DEMO[i+1][j+1]==0)             {Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}break;
	     case 5:    if(1){if(DEMO[i][j+1]==0&&DEMO[i+1][j]==0&&DEMO[i+1][j+1]==0&&DEMO[i+1][j+2]==0&&DEMO[i+2][j+1]==0){Rotate();}else{Y=temp_Y;i=temp_i;j=temp_j;Fr=temp_Fr;}}break;
	  }
	  //Boom ...|
       }
       if(V==27)
       {
	   gotoxy(30,15);printf("Are you sure to QUIT (Y / N):");
	   char YN=getche();
	   if(YN=='Y'||YN=='y')exit(0);
	   else if(YN=='n'||YN=='N'){gotoxy(30,15);printf("                                  ");}
       }
       setcolor(14);setfillstyle(1,GREEN);
       switch(SELECT)
       {
	 case 0:L();   break;
	 case 1:I();   break;
	 case 2:T();   break;
	 case 3:N();   break;
	 case 4:O();   break;
	 case 5:Plus();break;
       }
       if(V==9&&v==1){v=0;while(!kbhit());}
    }while(1);
}
void Rotate()
{
	  switch(SELECT)
	  {
	    case 0:Dir_L++;if(Dir_L==5)Dir_L=1;break;
	    case 1:Dir_I++;if(Dir_I==3)Dir_I=1;
			   if(Dir_I==2){X=X+40;DEMO[i][j+=2]=0;}
			   if(Dir_I==1){if(X>31||X>131){X=X-40;DEMO[i][j-=2]=0;}}
			   break;
	    case 2:Dir_T++;if(Dir_T==5)Dir_T=1;break;
	    case 3:Dir_N++;if(Dir_N==3)Dir_N=1;break;
	    case 4:                            break;
	    case 5:                            break;
	  }
}
void Plus()
{
   switch(Dir_Plus)
   {
     case 1:
     {
	if(X>151){X=X-20;DEMO[i][--j]=0;}
	bar(X+11,Y-9,X+29,Y+9);     //  o         1
	bar(X-9,Y+11,X+9,Y+29);     //o o o     2,3,4
	bar(X+11,Y+11,X+29,Y+29);   //  o         5
	bar(X+31,Y+11,X+49,Y+29);
	bar(X+11,Y+31,X+29,Y+49);
	break;
     }
   }
}
void O()
{
   switch(Dir_O)
   {
     case 1:
     {
	if(X>171){X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);	      //o o   1,2
	bar(X+11,Y-9,X+29,Y+9);       //o o   3,4
	bar(X-9,Y+11,X+9,Y+29);
	bar(X+11,Y+11,X+29,Y+29);
	break;
     }
   }
}
void N()
{
   switch(Dir_N)
   {
     case 1:
     {
	if(X>171){X=X-20;DEMO[i][--j]=0;}
	bar(X+11,Y-9,X+29,Y+9);     //  o    1
	bar(X-9,Y+11,X+9,Y+29);     //o o  2,3
	bar(X+11,Y+11,X+29,Y+29);   //o    4
	bar(X-9,Y+31,X+9,Y+49);
	break;
     }
     case 2:
     {
	if(X>151){X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);	     //o o       1,2
	bar(X+11,Y-9,X+29,Y+9);      //  o o       3,4
	bar(X+11,Y+11,X+29,Y+29);
	bar(X+31,Y+11,X+49,Y+29);
	break;
     }
   }
}
void T()
{
   switch(Dir_T)
   {
     case 1:
     {
	if(X>151){X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);       //o o o    1,2,3
	bar(X+11,Y-9,X+29,Y+9);     //  o        4
	bar(X+31,Y-9,X+49,Y+9);
	bar(X+11,Y+11,X+29,Y+29);
	break;
     }
     case 2:
     {
	if(X>171){ X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);       //o        1
	bar(X-9,Y+11,X+9,Y+29);     //o o      2,4
	bar(X-9,Y+31,X+9,Y+49);     //o        3
	bar(X+11,Y+11,X+29,Y+29);
	break;
     }
     case 3:
     {
	if(X>151){ X=X-20;DEMO[i][--j]=0;}
	bar(X+11,Y-9,X+29,Y+9);     //  o         1
	bar(X-9,Y+11,X+9,Y+29);     //o o o     2,3,4
	bar(X+11,Y+11,X+29,Y+29);
	bar(X+31,Y+11,X+49,Y+29);
	break;
     }
     case 4:
     {
	if(X>171) {X=X-20;DEMO[i][--j]=0;}
	bar(X+11,Y-9,X+29,Y+9);       //  o          1
	bar(X+11,Y+11,X+29,Y+29);     //o o        4,2
	bar(X+11,Y+31,X+29,Y+49);     //  o          3
	bar(X-9,Y+11,X+9,Y+29);
	break;
     }
   }
}
void I()
{
   switch(Dir_I)
   {
     case 1:
     {
	if(X>131) {X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);      //o o o o   1,2,3,4
	bar(X+11,Y-9,X+29,Y+9);
	bar(X+31,Y-9,X+49,Y+9);
	bar(X+51,Y-9,X+69,Y+9);
	break;
     }
     case 2:
     {
	bar(X-9,Y-9,X+9,Y+9);      //o  1
	bar(X-9,Y+11,X+9,Y+29);    //o  2
	bar(X-9,Y+31,X+9,Y+49);    //o  3
	bar(X-9,Y+51,X+9,Y+69);    //o  4
	break;
     }
   }
}
void L()
{
   switch(Dir_L)
   {
     case 1:
     {
	if(X>171) {X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);       //o        1
	bar(X-9,Y+11,X+9,Y+29);     //o        2
	bar(X-9,Y+31,X+9,Y+49);     //o o      3,4
	bar(X+11,Y+31,X+29,Y+49);
	break;
     }
     case 2:
     {
	if(X>151) {X=X-20;DEMO[i][--j]=0;}
	bar(X+31,Y-9,X+49,Y+9);     //    o         1
	bar(X-9,Y+11,X+9,Y+29);     //o o o     2,3,4
	bar(X+11,Y+11,X+29,Y+29);
	bar(X+31,Y+11,X+49,Y+29);
	break;
     }
     case 3:
     {
	if(X>171) {X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);        //o o     1,2
	bar(X+11,Y-9,X+29,Y+9);      //  o       3
	bar(X+11,Y+11,X+29,Y+29);    //  o       4
	bar(X+11,Y+31,X+29,Y+49);
	break;
     }
     case 4:
     {
	if(X>151) {X=X-20;DEMO[i][--j]=0;}
	bar(X-9,Y-9,X+9,Y+9);       //o o o    1,2,3
	bar(X+11,Y-9,X+29,Y+9);     //o        4
	bar(X+31,Y-9,X+49,Y+9);
	bar(X-9,Y+11,X+9,Y+29);
	break;
     }
   }
}
void graph()
{
   int gdriver=DETECT,gmode,errorcode;
   initgraph(&gdriver,&gmode,"");
   errorcode=graphresult();
   if(errorcode!=grOk)
   {
     printf("Graphics error: %s\n", grapherrormsg(errorcode));
     printf("Press any key to halt:");getch();exit(1);
   }
}
void venisoft()
{
    Y=180;
    for(X=660;X>70;X=X-3)
    {
       venix(X,Y,0);
       delay(10);
       cleardevice();
    }
    temp_X=X;temp_Y=Y;
    venix(temp_X,temp_Y,0);
    delay(1000);
    for(X=600,Y=10;X>300||Y<200;X=X-15,Y=Y+9)
    {
       setcolor(WHITE);setfillstyle(1,WHITE);
       venix(temp_X,temp_Y,0);
       bar(X,Y,X+commet,Y+commet);
       delay(50);
       setcolor(BLACK);setfillstyle(1,BLACK);
       bar(X,Y,X+commet,Y+commet);
       commet++;
    }
    sound(2000);delay(200);nosound();
    venix(temp_X,temp_Y,0);
    commet=20;
    for(X=temp_X,Y=temp_Y;commet<=100;X-=2,Y-=2,commet+=4)
    {
       setcolor(WHITE);setfillstyle(1,WHITE);
       venix(X,Y,-20+commet);
       delay(100);
       setcolor(BLACK);setfillstyle(1,BLACK);
       venix(X,Y,commet);
    }
    gotoxy(29,15);printf("Press ENTER to continue");
    getch();cleardevice();
}