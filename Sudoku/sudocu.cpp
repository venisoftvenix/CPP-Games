#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void venix();
void procedure();
void select_number();
void graph();
void initialization();
void levels();
void check();
void getit();
void print();
void security();
void num_table();
void table();
int a1[3][3],a2[3][3],a3[3][3],a4[3][3],a5[3][3],a6[3][3],a7[3][3],a8[3][3],a9[3][3],level=1;
int no=1,x=0,y=0,z=0,set=0,g=1,end=0,win=0;
void main()
{
   graph();
   venix();
   cleardevice();
   gotoxy(1,2);printf("INSTRUSTIONS :\n\nUse ARROW keys to move");
   printf("\n\nThe game consists of 10 LEVELS ,and you have to follow 2 steps.");
   printf("\nIn step 1 :\nSelect the number from the first selection values and then press ENTER to accept the selected value.");
   printf("\n\nIn step 2 :\nSelect the appropriate place and press ENTER.");
   printf("\n\n\nPress 'ESC' to EXIT at any time.\n\nPress ENTER to continue.");
   getch();
   cleardevice();
   do{
   no=1,x=0,y=0,z=0,set=0,g=1,end=0,win=0;
   initialization();
   while(win==0)
   {
      levels();
      print();
      table();
      num_table();
      procedure();
      if(win==1)break;
   }
   gotoxy(10,20);printf("You have completed level %d.Press enter to continue.",level);getch();
   gotoxy(10,20);printf("                                                         ");
   level++;
   win=0;
   if(level>10){gotoxy(10,20);printf("You won SUDOKU");getch();printf("                           ");exit(0);};
   }while(1);
}
void venix()
{
   gotoxy(25,2);printf("Programe by Venigandla Venkatesh");
   for(int i=1;i<10;i++)
    {
      setcolor(14);
      settextstyle(4,0,i);
      moveto(50,100);
      outtext("SUDOKU");
      setusercharsize(4,3,1,1);
      delay(800);
      setcolor(BLACK);
      settextstyle(4,0,i);
      moveto(50,100);
      outtext("SUDOKU");
      setusercharsize(4,3,1,1);
    }
    setcolor(14);
    settextstyle(4,0,i);
    moveto(50,100);
    outtext("SUDOKU");
    setusercharsize(4,3,1,1);
    delay(800);
    getch();
    setcolor(BLACK);
    settextstyle(4,0,i);
    moveto(50,100);
    outtext("SUDOKU");
    setusercharsize(4,3,1,1);
}
void getit()
{
   if(win==1)return;
   char k=219,c1;
   int v1=32,v2=10,v1pos=0,v1_pos=0,v2pos=0,v2_pos=0;
   x=0;y=0;z=0;
   do
   {
      gotoxy(3,14);printf("=>");
      gotoxy(v1,v2);printf("%c",k);
      int X;
      char c1;
      c1=(char)X;
      if(c1=='\r'||c1=='\n'||win==1)break;
      if(c1=='q'||c1=='Q')
      {
	 char i;
	 gotoxy(1,20);printf("Do you want to quit.(Y/N):");
	 i=getch();
	 if(i=='y'||i=='Y') exit(0);
	 else{gotoxy(1,20);printf("                                   ");}
      }
      X=getch();
      if(X==0)
      X=getch();
      if(z==1||z==0){gotoxy(v1,v2);if(a1[x][y]==0)printf(" ");else printf("%d",a1[x][y]);}
      if(z==2){gotoxy(v1,v2);if(a2[x][y]==0)printf(" ");else printf("%d",a2[x][y]);}
      if(z==3){gotoxy(v1,v2);if(a3[x][y]==0)printf(" ");else printf("%d",a3[x][y]);}
      if(z==4){gotoxy(v1,v2);if(a4[x][y]==0)printf(" ");else printf("%d",a4[x][y]);}
      if(z==5){gotoxy(v1,v2);if(a5[x][y]==0)printf(" ");else printf("%d",a5[x][y]);}
      if(z==6){gotoxy(v1,v2);if(a6[x][y]==0)printf(" ");else printf("%d",a6[x][y]);}
      if(z==7){gotoxy(v1,v2);if(a7[x][y]==0)printf(" ");else printf("%d",a7[x][y]);}
      if(z==8){gotoxy(v1,v2);if(a8[x][y]==0)printf(" ");else printf("%d",a8[x][y]);}
      if(z==9){gotoxy(v1,v2);if(a9[x][y]==0)printf(" ");else printf("%d",a9[x][y]);}
      table();
      if(X==77)
      {
	 v1=v1+2;
	 v1pos++;
	 if(v1>48)
	 {v1=v1-2;v1pos--;}
	 if(v1pos>2&&v1<=48)
	 {
	    v1_pos++;
	    v1pos=0;
	 }
	 y=v1pos;
      }
      else if(X==75)
      {
	 v1=v1-2;
	 v1pos--;
	 if(v1<32)
	 {v1=v1+2;v1pos++;}
	 if(v1pos<0&&v1>=32)
	 {
	    v1_pos--;
	    v1pos=2;
	 }
	 y=v1pos;
      }
      else if(X==80)
      {
	 v2++;
	 v2pos++;
	 if(v2>18)
	 {v2--;v2pos--;}
	 if(v2pos>2&&v2<=18)
	 {
	    v2_pos++;
	    v2pos=0;
	 }
	 x=v2pos;
      }
      else if(X==72)
      {
	 v2--;
	 v2pos--;
	 if(v2<10)
	 {v2++;v2pos++;}
	 if(v2pos<0&&v2>=10)
	 {
	    v2_pos--;
	    v2pos=2;
	 }
	 x=v2pos;
      }

	     if(v1_pos==0&&v2_pos==0)z=1;
      else if(v1_pos==0&&v2_pos==1)z=4;
      else if(v1_pos==0&&v2_pos==2)z=7;
      else if(v1_pos==1&&v2_pos==0)z=2;
      else if(v1_pos==1&&v2_pos==1)z=5;
      else if(v1_pos==1&&v2_pos==2)z=8;
      else if(v1_pos==2&&v2_pos==0)z=3;
      else if(v1_pos==2&&v2_pos==1)z=6;
      else if(v1_pos==2&&v2_pos==2)z=9;
   }while(c1!='\r');
   gotoxy(3,14);printf("  ");
}
void check()
{
   if(win==1)return;
   set=0;end++; int sum[10],count=0;
   for(int j=0;j<3;j++)
   {
      if(z==1||z==2||z==3)
	if(a1[x][j]==no||a2[x][j]==no||a3[x][j]==no)set++;
      if(z==4||z==5||z==6)
	if(a4[x][j]==no||a5[x][j]==no||a6[x][j]==no)set++;
      if(z==7||z==8||z==9)
	if(a7[x][j]==no||a8[x][j]==no||a9[x][j]==no)set++;
      if(z==1||z==4||z==7)
	if(a1[j][y]==no||a4[j][y]==no||a7[j][y]==no)set++;
      if(z==2||z==5||z==8)
	if(a2[j][y]==no||a5[j][y]==no||a8[j][y]==no)set++;
      if(z==3||z==6||z==9)
	if(a3[j][y]==no||a6[j][y]==no||a9[j][y]==no)set++;
   }
   int i;
   switch(z)
   {
     case 1:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a1[i][j]==no)set++;break;
     case 2:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a2[i][j]==no)set++;break;
     case 3:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a3[i][j]==no)set++;break;
     case 4:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a4[i][j]==no)set++;break;
     case 5:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a5[i][j]==no)set++;break;
     case 6:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a6[i][j]==no)set++;break;
     case 7:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a7[i][j]==no)set++;break;
     case 8:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a8[i][j]==no)set++;break;
     case 9:for(i=0;i<3;i++)for(j=0;j<3;j++)if(a9[i][j]==no)set++;break;
   }
   //if(end>65)
   {
	 count=0;
	 for(i=0;i<9;i++)sum[i]=0;
	 for(j=0;j<3;j++)
	 {
	    sum[0]=sum[0]+a1[0][j]+a2[0][j]+a3[0][j];
	    sum[1]=sum[1]+a1[1][j]+a2[1][j]+a3[1][j];
	    sum[2]=sum[2]+a1[2][j]+a2[2][j]+a3[2][j];
	    sum[3]=sum[3]+a4[0][j]+a5[0][j]+a6[0][j];
	    sum[4]=sum[4]+a4[1][j]+a5[1][j]+a6[1][j];
	    sum[5]=sum[5]+a4[2][j]+a5[2][j]+a6[2][j];
	    sum[6]=sum[6]+a7[0][j]+a8[0][j]+a9[0][j];
	    sum[7]=sum[7]+a7[1][j]+a8[1][j]+a9[1][j];
	    sum[8]=sum[8]+a7[2][j]+a8[2][j]+a9[2][j];
	 }
	 if(sum[0]==45&&sum[1]==45&&sum[2]==45&&sum[3]==45&&sum[4]==45&&sum[5]==45&&sum[6]==45&&sum[7]==45&&sum[8]==45)
				   count++;
	 for(i=0;i<9;i++)sum[i]=0;
	 for(j=0;j<3;j++)
	 {
	    sum[0]=sum[0]+a1[j][0]+a4[j][0]+a7[j][0];
	    sum[1]=sum[1]+a1[j][1]+a4[j][1]+a7[j][1];
	    sum[2]=sum[2]+a1[j][2]+a4[j][2]+a7[j][2];
	    sum[3]=sum[3]+a2[j][0]+a5[j][0]+a8[j][0];
	    sum[4]=sum[4]+a2[j][1]+a5[j][1]+a8[j][1];
	    sum[5]=sum[5]+a2[j][2]+a5[j][2]+a8[j][2];
	    sum[6]=sum[6]+a3[j][0]+a6[j][0]+a9[j][0];
	    sum[7]=sum[7]+a3[j][1]+a6[j][1]+a9[j][1];
	    sum[8]=sum[8]+a3[j][2]+a6[j][2]+a9[j][2];
	 }
	 if(sum[0]==45&&sum[1]==45&&sum[2]==45&&sum[3]==45&&sum[4]==45&&sum[5]==45&&sum[6]==45&&sum[7]==45&&sum[8]==45)
				   count++;
	 for(i=0;i<9;i++)sum[i]=0;
	 for(i=0;i<3;i++)
	    for(j=0;j<3;j++)
	    {
	       sum[0]=sum[0]+a1[i][j];
	       sum[1]=sum[1]+a2[i][j];
	       sum[2]=sum[2]+a3[i][j];
	       sum[3]=sum[3]+a4[i][j];
	       sum[4]=sum[4]+a5[i][j];
	       sum[5]=sum[5]+a6[i][j];
	       sum[6]=sum[6]+a7[i][j];
	       sum[7]=sum[7]+a8[i][j];
	       sum[8]=sum[8]+a9[i][j];
	    }
	  if(sum[0]==45&&sum[1]==45&&sum[2]==45&&sum[3]==45&&sum[4]==45&&sum[5]==45&&sum[6]==45&&sum[7]==45&&sum[8]==45)
				   count++;
	  if(count==3)win=1;
   }
}
void procedure()
{
   if(win==1)return;
   int sum=0,count=0;
   switch(z)
   {
      case 1:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a1[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 2:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a2[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 3:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a3[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 4:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a4[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 5:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a5[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 6:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a6[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 7:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a7[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 8:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a8[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
      case 9:check();if(win==0)security();else return;if(set==0&&g==1&&win==0)a9[x][y]=no;else if(set!=0&&g==1&&win==0){gotoxy(1,20);printf("WARNING:Either ROW or COLLUM or BLOCK is filled with this number.Press ENTER to continue");getch();gotoxy(1,20);printf("                                                                                        ");}check();break;
   }
}
void num_table()
{
   if(win==1)return;
   gotoxy(3,5);printf("=>");
   for(int i=1;i<10;i++)
    {
      gotoxy(18+i*4,5);printf("%d",i);
   }
   char c='1'; no=1;
   do
   {
       if(no==1)setcolor(WHITE); else setcolor(BLACK);rectangle(155,60,187,80);
       if(no==2)setcolor(WHITE); else setcolor(BLACK);rectangle(188,60,220,80);
       if(no==3)setcolor(WHITE); else setcolor(BLACK);rectangle(221,60,252,80);
       if(no==4)setcolor(WHITE); else setcolor(BLACK);rectangle(253,60,283,80);
       if(no==5)setcolor(WHITE); else setcolor(BLACK);rectangle(284,60,315,80);
       if(no==6)setcolor(WHITE); else setcolor(BLACK);rectangle(316,60,348,80);
       if(no==7)setcolor(WHITE); else setcolor(BLACK);rectangle(349,60,380,80);
       if(no==8)setcolor(WHITE); else setcolor(BLACK);rectangle(381,60,412,80);
       if(no==9)setcolor(WHITE); else setcolor(BLACK);rectangle(413,60,445,80);
      int X;
      char c1;
      c1=(char)X;
      if(c1=='\r'||c1=='\n'||win==1)break;
      if(c1==27)
      {
	 char i;
	 gotoxy(1,20);printf("Do you want to quit.(Y/N):");
	 i=getch();
	 if(i=='y'||i=='Y') exit(0);
	 else{gotoxy(1,20);printf("                                   ");}
      }
      X=getch();
      if(X==0)
      X=getch();
       if(X==77)
       {
	   no++;
	   if(no>9)no--;
       }
       else if(X==75)
       {
	  no--;
	  if(no<1)no++;
       }
   }while(c!='\r');
   gotoxy(3,5);printf("  ");
   getit();
}
void initialization()
{
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
	  a1[i][j]=NULL; a2[i][j]=NULL; a3[i][j]=NULL;
	  a4[i][j]=NULL; a5[i][j]=NULL; a6[i][j]=NULL;
	  a7[i][j]=NULL; a8[i][j]=NULL; a9[i][j]=NULL;
      }
   }
}
void levels()
{
   if(win==1)return;
   gotoxy(35,25);printf("Level : %d",level);
   switch(level)
   {
      case  1:a1[0][0]=8;a1[0][1]=5;a1[1][1]=2;a1[2][1]=6;a1[2][2]=1;a2[1][0]=3;a2[2][0]=4;a3[0][1]=6;a3[1][0]=7;a4[2][0]=6;a5[1][0]=1;a5[1][1]=5;a5[1][2]=9;a5[0][2]=3;a5[2][0]=2;a6[0][2]=9;a7[2][1]=9;a7[1][2]=5;a8[0][2]=2;a8[1][2]=1;a9[0][0]=3;a9[0][1]=5;a9[1][1]=8;a9[2][1]=4;a9[2][2]=2;break;
      case  2:a1[0][2]=8;a1[2][0]=1;a2[1][0]=5;a2[1][2]=4;a2[2][2]=9;a3[0][2]=3;a3[1][1]=6;a3[2][0]=4;a3[2][2]=2;a4[0][2]=5;a4[1][1]=1;a4[2][0]=7;a4[2][1]=8;a6[0][1]=8;a6[0][2]=9;a6[1][1]=7;a6[2][0]=6;a7[0][0]=4;a7[0][2]=7;a7[1][1]=3;a7[2][0]=9;a8[0][0]=3;a8[1][0]=9;a8[1][2]=1;a9[0][2]=6;a9[2][0]=2;break;
      case  3:a1[1][0]=4;a1[2][0]=5;a1[2][2]=7;a2[1][0]=8;a2[0][1]=7;a2[2][1]=6;a2[2][2]=1;a3[0][0]=9;a3[1][1]=2;a3[1][2]=1;a3[2][1]=3;a4[0][2]=1;a4[2][1]=7;a5[0][0]=6;a5[2][2]=9;a6[0][1]=4;a6[2][0]=1;a7[0][1]=9;a7[1][0]=8;a7[1][1]=5;a7[2][2]=2;a8[0][0]=3;a8[0][1]=8;a8[1][2]=2;a8[2][1]=1;a9[0][0]=2;a9[0][2]=5;a9[1][2]=4;break;
      case  4:a1[0][0]=4;a1[0][1]=9;a1[1][1]=6;a1[2][0]=3;a2[1][0]=5;a2[2][0]=9;a2[1][2]=8;a2[2][2]=7;a3[0][1]=6;a3[0][2]=5;a3[1][1]=9;a3[2][2]=2;a4[1][1]=2;a5[0][0]=2;a5[1][1]=8;a5[0][2]=1;a5[2][0]=3;a5[2][2]=9;a6[1][1]=5;a7[0][0]=1;a7[1][1]=3;a7[2][0]=6;a7[2][1]=5;a8[0][0]=6;a8[1][0]=8;a8[0][2]=2;a8[1][2]=5;a9[0][2]=3;a9[1][1]=4;a9[2][1]=2;a9[2][2]=1;break;
      case  5:a1[0][2]=9;a1[2][0]=5;a2[0][1]=2;a2[0][2]=6;a2[1][0]=8;a2[2][0]=4;a3[1][1]=2;a3[2][0]=6;a3[2][2]=8;a4[0][2]=3;a4[1][0]=6;a4[2][0]=9;a4[2][1]=4;a5[0][2]=8;a5[2][0]=1;a6[0][1]=1;a6[0][2]=9;a6[1][2]=3;a6[2][0]=5;a7[0][0]=7;a7[1][1]=8;a7[0][2]=1;a8[0][2]=5;a8[1][2]=1;a8[2][0]=3;a8[2][1]=7;a9[0][2]=4;a9[2][0]=9;break;
      case  6:a1[1][0]=6;a1[2][1]=3;a1[1][2]=1;a2[0][1]=1;a2[2][0]=5;a2[2][2]=9;a3[1][0]=5;a3[1][2]=4;a3[2][1]=8;a4[0][0]=8;a4[0][2]=2;a4[1][1]=4;a4[2][0]=7;a4[2][2]=5;a5[0][0]=6;a5[0][2]=4;a5[2][0]=2;a5[2][2]=3;a6[2][0]=8;a6[2][2]=1;a6[0][0]=7;a6[0][2]=9;a6[1][1]=6;a6[2][0]=8;a6[2][2]=1;a7[0][1]=8;a7[1][0]=3;a7[1][2]=6;a8[0][0]=1;a8[0][2]=2;a8[2][1]=6;a9[0][1]=7;a9[1][0]=4;a9[1][2]=8;break;
      case  7:a1[0][0]=2;a1[1][1]=1;a1[2][1]=7;a1[2][2]=3;a2[0][0]=9;a2[1][1]=3;a2[0][2]=5;a3[0][2]=7;a3[1][1]=8;a3[2][0]=1;a3[2][1]=6;a4[1][0]=7;a4[0][2]=6;a4[2][2]=5;a5[0][0]=4;a5[0][2]=9;a5[2][0]=3;a5[2][2]=2;a6[0][0]=7;a6[1][2]=2;a6[2][0]=6;a7[0][1]=9;a7[0][2]=1;a7[1][1]=5;a7[2][0]=8;a8[1][1]=6;a8[2][0]=5;a8[2][2]=1;a9[0][0]=5;a9[0][1]=4;a9[1][1]=7;a9[2][2]=6;break;
      case  8:a1[0][1]=8;a1[1][0]=6;a1[1][2]=3;a2[0][0]=9;a2[0][2]=3;a3[0][1]=7;a3[1][0]=4;a3[1][2]=1;a4[0][0]=5;a4[1][0]=9;a4[1][1]=6;a4[2][0]=2;a5[0][1]=2;a5[1][1]=1;a5[2][1]=9;a6[1][1]=4;a6[0][2]=3;a6[1][2]=7;a6[2][2]=8;a7[1][0]=4;a7[1][2]=5;a7[2][1]=2;a8[2][0]=5;a8[2][2]=1;a9[1][0]=6;a9[1][2]=2;a9[2][1]=3;break;
      case  9:a1[1][1]=7;a1[0][2]=8;a1[2][2]=5;a2[0][0]=6;a2[0][1]=2;a2[1][0]=3;a2[2][2]=4;a3[0][0]=4;a3[0][1]=3;a3[2][2]=6;a4[1][0]=7;a4[1][2]=3;a5[0][2]=8;a5[1][1]=6;a5[2][0]=5;a6[1][0]=9;a6[1][2]=8;a7[0][0]=1;a7[2][1]=5;a7[2][2]=2;a8[0][0]=4;a8[1][2]=2;a8[2][1]=3;a8[2][2]=6;a9[0][0]=7;a9[1][1]=6;a9[2][0]=8;break;
      case 10:a1[0][1]=2;a1[2][2]=9;a2[0][1]=1;a2[0][2]=8;a2[1][0]=9;a2[2][0]=2;a2[2][2]=3;a3[1][1]=5;a3[2][1]=4;a4[0][0]=2;a4[0][2]=1;a4[2][2]=8;a5[0][0]=3;a5[1][1]=6;a5[2][2]=4;a6[0][0]=9;a6[2][0]=3;a6[2][2]=6;a7[0][1]=9;a7[1][1]=1;a8[0][0]=5;a8[0][2]=6;a8[1][2]=2;a8[2][0]=4;a8[2][1]=7;a9[0][0]=4;a9[2][1]=9;break;
   }
}
void security()
{
   if(win==1)return;
   g=1;
   switch(level)
   {
      case 1:if((x==0&&y==0&&z==1)||(x==0&&y==1&&z==1)||(x==1&&y==1&&z==1)||(x==2&&y==1&&z==1)||(x==2&&y==2&&z==1)||(x==1&&y==0&&z==2)||(x==2&&y==0&&z==2)||(x==0&&y==1&&z==3)||(x==1&&y==0&&z==3)||(x==2&&y==0&&z==4)||(x==0&&y==2&&z==5)||(x==1&&y==0&&z==5)||(x==1&&y==1&&z==5)||(x==1&&y==2&&z==5)||(x==2&&y==0&&z==5)||(x==0&&y==2&&z==6)||(x==1&&y==2&&z==7)||(x==2&&y==1&&z==7)||(x==0&&y==2&&z==8)||(x==1&&y==2&&z==8)||(x==0&&y==0&&z==9)||(x==0&&y==1&&z==9)||(x==1&&y==1&&z==9)||(x==2&&y==1&&z==9)||(x==2&&y==2&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 2:if((x==0&&y==2&&z==1)||(x==2&&y==0&&z==1)||(x==1&&y==0&&z==2)||(x==1&&y==2&&z==2)||(x==2&&y==2&&z==2)||(x==0&&y==1&&z==3)||(x==1&&y==1&&z==3)||(x==2&&y==0&&z==3)||(x==2&&y==2&&z==3)||(x==0&&y==2&&z==4)||(x==1&&y==1&&z==4)||(x==2&&y==0&&z==4)||(x==2&&y==1&&z==4)||(x==0&&y==2&&z==6)||(x==1&&y==1&&z==6)||(x==2&&y==0&&z==6)||(x==0&&y==1&&z==6)||(x==0&&y==2&&z==7)||(x==1&&y==1&&z==7)||(x==2&&y==0&&z==7)||(x==0&&y==0&&z==7)||(x==0&&y==0&&z==8)||(x==1&&y==0&&z==8)||(x==1&&y==2&&z==8)||(x==0&&y==2&&z==9)||(x==2&&y==0&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 3:if((x==1&&y==0&&z==1)||(x==2&&y==0&&z==1)||(x==2&&y==2&&z==1)||(x==0&&y==1&&z==2)||(x==1&&y==0&&z==2)||(x==2&&y==1&&z==2)||(x==2&&y==2&&z==2)||(x==0&&y==0&&z==3)||(x==1&&y==1&&z==3)||(x==1&&y==2&&z==3)||(x==2&&y==1&&z==3)||(x==0&&y==2&&z==4)||(x==2&&y==1&&z==4)||(x==0&&y==0&&z==5)||(x==2&&y==2&&z==5)||(x==0&&y==1&&z==6)||(x==2&&y==0&&z==6)||(x==0&&y==1&&z==7)||(x==1&&y==0&&z==7)||(x==1&&y==1&&z==7)||(x==2&&y==2&&z==7)||(x==0&&y==0&&z==8)||(x==0&&y==1&&z==8)||(x==1&&y==2&&z==8)||(x==2&&y==1&&z==8)||(x==0&&y==0&&z==9)||(x==0&&y==2&&z==9)||(x==1&&y==2&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 4:if((x==0&&y==0&&z==1)||(x==0&&y==1&&z==1)||(x==1&&y==1&&z==1)||(x==2&&y==0&&z==1)||(x==1&&y==0&&z==2)||(x==2&&y==0&&z==2)||(x==1&&y==2&&z==2)||(x==2&&y==2&&z==2)||(x==0&&y==1&&z==3)||(x==0&&y==2&&z==3)||(x==1&&y==1&&z==3)||(x==2&&y==2&&z==3)||(x==1&&y==1&&z==4)||(x==0&&y==0&&z==5)||(x==0&&y==2&&z==5)||(x==1&&y==1&&z==5)||(x==2&&y==0&&z==5)||(x==2&&y==2&&z==5)||(x==1&&y==1&&z==6)||(x==0&&y==0&&z==7)||(x==1&&y==1&&z==7)||(x==2&&y==0&&z==7)||(x==2&&y==1&&z==7)||(x==0&&y==0&&z==8)||(x==1&&y==0&&z==8)||(x==0&&y==2&&z==8)||(x==1&&y==2&&z==8)||(x==0&&y==2&&z==9)||(x==1&&y==1&&z==9)||(x==2&&y==1&&z==9)||(x==2&&y==2&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 5:if((x==0&&y==2&&z==1)||(x==2&&y==0&&z==1)||(x==0&&y==1&&z==2)||(x==0&&y==2&&z==2)||(x==1&&y==0&&z==2)||(x==2&&y==0&&z==2)||(x==1&&y==1&&z==3)||(x==2&&y==0&&z==3)||(x==2&&y==2&&z==3)||(x==0&&y==2&&z==4)||(x==1&&y==0&&z==4)||(x==2&&y==0&&z==4)||(x==2&&y==1&&z==4)||(x==0&&y==2&&z==5)||(x==2&&y==0&&z==5)||(x==0&&y==1&&z==6)||(x==0&&y==2&&z==6)||(x==1&&y==2&&z==6)||(x==2&&y==0&&z==6)||(x==0&&y==0&&z==7)||(x==1&&y==1&&z==7)||(x==0&&y==2&&z==7)||(x==0&&y==2&&z==8)||(x==1&&y==2&&z==8)||(x==2&&y==0&&z==8)||(x==2&&y==1&&z==8)||(x==0&&y==2&&z==9)||(x==2&&y==0&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 6:if((x==1&&y==0&&z==1)||(x==1&&y==2&&z==1)||(x==2&&y==1&&z==1)||(x==0&&y==1&&z==2)||(x==2&&y==0&&z==2)||(x==2&&y==2&&z==2)||(x==1&&y==0&&z==3)||(x==1&&y==2&&z==3)||(x==2&&y==1&&z==3)||(x==0&&y==0&&z==4)||(x==0&&y==2&&z==4)||(x==1&&y==1&&z==4)||(x==2&&y==0&&z==4)||(x==2&&y==2&&z==4)||(x==0&&y==0&&z==5)||(x==0&&y==2&&z==5)||(x==2&&y==0&&z==5)||(x==2&&y==2&&z==5)||(x==0&&y==0&&z==6)||(x==1&&y==1&&z==6)||(x==0&&y==2&&z==6)||(x==2&&y==0&&z==6)||(x==2&&y==2&&z==6)||(x==0&&y==1&&z==7)||(x==1&&y==0&&z==7)||(x==1&&y==2&&z==7)||(x==0&&y==0&&z==8)||(x==0&&y==2&&z==8)||(x==2&&y==1&&z==8)||(x==0&&y==1&&z==9)||(x==1&&y==0&&z==9)||(x==1&&y==2&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 7:if((x==0&&y==0&&z==1)||(x==1&&y==1&&z==1)||(x==2&&y==2&&z==1)||(x==2&&y==1&&z==1)||(x==0&&y==0&&z==2)||(x==0&&y==2&&z==2)||(x==1&&y==1&&z==2)||(x==0&&y==2&&z==3)||(x==1&&y==1&&z==3)||(x==2&&y==0&&z==3)||(x==2&&y==1&&z==3)||(x==0&&y==2&&z==4)||(x==1&&y==0&&z==4)||(x==2&&y==2&&z==4)||(x==0&&y==0&&z==5)||(x==0&&y==2&&z==5)||(x==2&&y==0&&z==5)||(x==2&&y==2&&z==5)||(x==0&&y==0&&z==6)||(x==1&&y==2&&z==6)||(x==2&&y==0&&z==6)||(x==0&&y==1&&z==7)||(x==0&&y==2&&z==7)||(x==1&&y==1&&z==7)||(x==2&&y==0&&z==7)||(x==1&&y==1&&z==8)||(x==2&&y==0&&z==8)||(x==2&&y==2&&z==8)||(x==0&&y==0&&z==9)||(x==0&&y==1&&z==9)||(x==1&&y==1&&z==9)||(x==2&&y==2&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 8:if((x==0&&y==1&&z==1)||(x==1&&y==0&&z==1)||(x==1&&y==2&&z==1)||(x==0&&y==0&&z==2)||(x==0&&y==2&&z==2)||(x==1&&y==0&&z==3)||(x==0&&y==1&&z==3)||(x==1&&y==2&&z==3)||(x==0&&y==0&&z==4)||(x==1&&y==1&&z==4)||(x==1&&y==0&&z==4)||(x==2&&y==0&&z==4)||(x==0&&y==1&&z==5)||(x==1&&y==1&&z==5)||(x==2&&y==1&&z==5)||(x==1&&y==1&&z==6)||(x==0&&y==2&&z==6)||(x==1&&y==2&&z==6)||(x==2&&y==2&&z==6)||(x==1&&y==0&&z==7)||(x==2&&y==1&&z==7)||(x==1&&y==2&&z==7)||(x==2&&y==0&&z==8)||(x==2&&y==2&&z==8)||(x==1&&y==0&&z==9)||(x==2&&y==1&&z==9)||(x==1&&y==2&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 9:if((x==0&&y==2&&z==1)||(x==1&&y==1&&z==1)||(x==2&&y==2&&z==1)||(x==0&&y==0&&z==2)||(x==0&&y==1&&z==2)||(x==1&&y==0&&z==2)||(x==2&&y==2&&z==2)||(x==0&&y==0&&z==3)||(x==0&&y==1&&z==3)||(x==2&&y==2&&z==3)||(x==1&&y==0&&z==4)||(x==1&&y==2&&z==4)||(x==0&&y==2&&z==5)||(x==1&&y==1&&z==5)||(x==2&&y==0&&z==5)||(x==1&&y==0&&z==6)||(x==1&&y==2&&z==6)||(x==0&&y==0&&z==7)||(x==2&&y==1&&z==7)||(x==2&&y==2&&z==7)||(x==0&&y==0&&z==8)||(x==1&&y==2&&z==8)||(x==2&&y==1&&z==8)||(x==2&&y==2&&z==8)||(x==0&&y==0&&z==9)||(x==1&&y==1&&z==9)||(x==2&&y==0&&z==9))
	     {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	     }break;
      case 10:if((x==0&&y==1&&z==1)||(x==2&&y==2&&z==1)||(x==0&&y==1&&z==2)||(x==0&&y==2&&z==2)||(x==1&&y==0&&z==2)||(x==2&&y==0&&z==2)||(x==2&&y==2&&z==2)||(x==1&&y==1&&z==3)||(x==2&&y==1&&z==3)||(x==0&&y==0&&z==4)||(x==0&&y==2&&z==4)||(x==2&&y==2&&z==4)||(x==0&&y==0&&z==5)||(x==1&&y==1&&z==5)||(x==2&&y==2&&z==5)||(x==0&&y==0&&z==6)||(x==2&&y==0&&z==6)||(x==2&&y==2&&z==6)||(x==0&&y==1&&z==7)||(x==1&&y==1&&z==7)||(x==0&&y==0&&z==8)||(x==0&&y==2&&z==8)||(x==1&&y==2&&z==8)||(x==2&&y==0&&z==8)||(x==2&&y==1&&z==8)||(x==0&&y==0&&z==9)||(x==2&&y==1&&z==9))
	      {
		g=0;
		gotoxy(1,20);printf("WARNING:This is a fixed value,You have no permition to change the value.Press ENTER to continue.");getch();
		gotoxy(1,20);printf("                                                                                                ");
	      }break;
   }
}
void print()
{
    if(win==1)return;
    for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
       {
	  gotoxy(32+j*2,i+10);if(a1[i][j]==0)printf(" ");else printf("%d ",a1[i][j]);
	  gotoxy(38+j*2,i+10);if(a2[i][j]==0)printf(" ");else printf("%d ",a2[i][j]);
	  gotoxy(44+j*2,i+10);if(a3[i][j]==0)printf(" ");else printf("%d ",a3[i][j]);
	  gotoxy(32+j*2,i+13);if(a4[i][j]==0)printf(" ");else printf("%d ",a4[i][j]);
	  gotoxy(38+j*2,i+13);if(a5[i][j]==0)printf(" ");else printf("%d ",a5[i][j]);
	  gotoxy(44+j*2,i+13);if(a6[i][j]==0)printf(" ");else printf("%d ",a6[i][j]);
	  gotoxy(32+j*2,i+16);if(a7[i][j]==0)printf(" ");else printf("%d ",a7[i][j]);
	  gotoxy(38+j*2,i+16);if(a8[i][j]==0)printf(" ");else printf("%d ",a8[i][j]);
	  gotoxy(44+j*2,i+16);if(a9[i][j]==0)printf(" ");else printf("%d ",a9[i][j]);
       }
}
void graph()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
     printf("Graphics error: %s\n", grapherrormsg(errorcode));
     printf("Press any key to halt:");
     getch();
     exit(1);
   }
}
void table()
{
   if(win==1)return;
   gotoxy(3,17);printf("=>");
   setcolor(WHITE);
   line(259,140,259,288); //1     //Vertical
   line(275,140,275,288); //2
   line(307,140,307,288); //4
   line(323,140,323,288); //5
   line(356,140,356,288); //7
   line(372,140,372,288); //8
   setcolor(14);
   rectangle(243,140,388,288);   //Border
   setcolor(BLUE);
   line(291,140,291,288); //3
   line(340,140,340,288); //6
   line(243,190,388,190); //3    //Horizantal
   line(243,238,388,238); //6
   setcolor(WHITE);
   line(243,158,388,158); //1
   line(243,174,388,174); //2
   line(243,206,388,206); //4
   line(243,222,388,222); //5
   line(243,254,388,254); //7
   line(243,270,388,270); //8
   gotoxy(3,17);printf("  ");
}
