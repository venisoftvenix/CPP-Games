#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void graph(); void venix();void poles();   int error();
void A();void B();void C();
int push_A(char x); int push_B(char x); int push_C(char x);
char pop_A();       char pop_B();       char pop_C();
void ask(); int procedure();
int top_A=0,top_B=-1,top_C=-1,i;char t,temp;
int disks;
char a[11]={"           "},b[11]={"           "},c[11]={"           "};
int X_top_A=12,X_top_B=12,X_top_C=12;
int va=0,vb=0,vc=0;
int choice;
int con=1,BOT_A=200,BOT_B=200,BOT_C=200;
void main()
{
    graph();
    venix();
    for(i=0;i<10;i++)
    {
       a[i]='9';b[i]='9';c[i]='9';
    }
    graph();
    gotoxy(25,6);printf("How many disks you want (Max=8):");scanf("%d",&disks);gotoxy(25,6);printf("                                   ");
    poles();
    for(i=0;i<disks;++i,++top_A)
    {
       a[i]=disks-i;
       gotoxy(15,--X_top_A);printf("%d",a[i]); A();
    }
    --X_top_A;--top_A;  va=1;
    do
    {
       ask();
       procedure();
    }while(1);
    getch();
}
void venix()
{
    gotoxy(26,1);printf("Programe by Venigandla Venkatesh");
    for(int i=449;i>100;i-=2)
    {
      setcolor(14);
      settextstyle(5,0,4);
      moveto(3,20+i);
      outtext("   Towers");
      setusercharsize(4, 3, 1, 1);
      moveto(300+i,300);
      outtext("Hanoi");
      moveto(180+i,100+i);
      outtext("Of");
      delay(100);
      setcolor(BLACK);
      moveto(300+i,300);
      outtext("Hanoi");
      settextstyle(5,0,4);
      moveto(3,20+i);
      outtext("   Towers");
      setusercharsize(4, 3, 1, 1);
      moveto(180+i,100+i);
      outtext("Of");
    }
    setcolor(14);
    settextstyle(5,0,4);
    moveto(3,20+i);
    outtext("   Towers");
    setusercharsize(4, 3, 1, 1);
    moveto(180+i,100+i);
    outtext("Of");
    moveto(300+i,300);
    outtext("Hanoi");
    getch();
    setcolor(BLACK);
    settextstyle(5,0,4);
    moveto(3,20+i);
    outtext("   Towers");
    setusercharsize(4, 3, 1, 1);
    moveto(180-i,100+i);
    outtext("of");
    closegraph();
}
void A()
{
    if(con==0)
    {
       BOT_A=BOT_A+10;
       switch(a[top_A])
       {
	   case 10:setcolor(BLACK);rectangle(105,BOT_A-10,205,BOT_A-1);break;
	   case  9:setcolor(BLACK);rectangle(110,BOT_A-10,200,BOT_A-1);break;
	   case  8:setcolor(BLACK);rectangle(115,BOT_A-10,195,BOT_A-1);break;
	   case  7:setcolor(BLACK);rectangle(120,BOT_A-10,190,BOT_A-1);break;
	   case  6:setcolor(BLACK);rectangle(125,BOT_A-10,185,BOT_A-1);break;
	   case  5:setcolor(BLACK);rectangle(130,BOT_A-10,180,BOT_A-1);break;
	   case  4:setcolor(BLACK);rectangle(135,BOT_A-10,175,BOT_A-1);break;
	   case  3:setcolor(BLACK);rectangle(140,BOT_A-10,170,BOT_A-1);break;
	   case  2:setcolor(BLACK);rectangle(145,BOT_A-10,165,BOT_A-1);break;
	   case  1:setcolor(BLACK);rectangle(150,BOT_A-10,160,BOT_A-1);break;
       }
    }
    else if(con==1)
    {
       switch(a[top_A])
       {
	   case 10:setcolor(WHITE);rectangle(105,BOT_A-10,205,BOT_A-1);break;
	   case  9:setcolor(WHITE);rectangle(110,BOT_A-10,200,BOT_A-1);break;
	   case  8:setcolor(WHITE);rectangle(115,BOT_A-10,195,BOT_A-1);break;
	   case  7:setcolor(WHITE);rectangle(120,BOT_A-10,190,BOT_A-1);break;
	   case  6:setcolor(WHITE);rectangle(125,BOT_A-10,185,BOT_A-1);break;
	   case  5:setcolor(WHITE);rectangle(130,BOT_A-10,180,BOT_A-1);break;
	   case  4:setcolor(WHITE);rectangle(135,BOT_A-10,175,BOT_A-1);break;
	   case  3:setcolor(WHITE);rectangle(140,BOT_A-10,170,BOT_A-1);break;
	   case  2:setcolor(WHITE);rectangle(145,BOT_A-10,165,BOT_A-1);break;
	   case  1:setcolor(WHITE);rectangle(150,BOT_A-10,160,BOT_A-1);break;
       }
       BOT_A=BOT_A-10;
    }
}
void B()
{
   if(con==0)
   {
     BOT_B=BOT_B+10;
     switch(b[top_B])
     {
       case 10:setcolor(BLACK);rectangle(265,BOT_B-10,365,BOT_B-1);break;
       case  9:setcolor(BLACK);rectangle(270,BOT_B-10,360,BOT_B-1);break;
       case  8:setcolor(BLACK);rectangle(275,BOT_B-10,355,BOT_B-1);break;
       case  7:setcolor(BLACK);rectangle(280,BOT_B-10,350,BOT_B-1);break;
       case  6:setcolor(BLACK);rectangle(285,BOT_B-10,345,BOT_B-1);break;
       case  5:setcolor(BLACK);rectangle(290,BOT_B-10,340,BOT_B-1);break;
       case  4:setcolor(BLACK);rectangle(295,BOT_B-10,335,BOT_B-1);break;
       case  3:setcolor(BLACK);rectangle(300,BOT_B-10,330,BOT_B-1);break;
       case  2:setcolor(BLACK);rectangle(305,BOT_B-10,325,BOT_B-1);break;
       case  1:setcolor(BLACK);rectangle(310,BOT_B-10,320,BOT_B-1);break;
     }
   }
   else if(con==1)
   {
     switch(b[top_B])
     {
       case 10:setcolor(WHITE);rectangle(265,BOT_B-10,365,BOT_B-1);break;
       case  9:setcolor(WHITE);rectangle(270,BOT_B-10,360,BOT_B-1);break;
       case  8:setcolor(WHITE);rectangle(275,BOT_B-10,355,BOT_B-1);break;
       case  7:setcolor(WHITE);rectangle(280,BOT_B-10,350,BOT_B-1);break;
       case  6:setcolor(WHITE);rectangle(285,BOT_B-10,345,BOT_B-1);break;
       case  5:setcolor(WHITE);rectangle(290,BOT_B-10,340,BOT_B-1);break;
       case  4:setcolor(WHITE);rectangle(295,BOT_B-10,335,BOT_B-1);break;
       case  3:setcolor(WHITE);rectangle(300,BOT_B-10,330,BOT_B-1);break;
       case  2:setcolor(WHITE);rectangle(305,BOT_B-10,325,BOT_B-1);break;
       case  1:setcolor(WHITE);rectangle(310,BOT_B-10,320,BOT_B-1);break;
     }
     BOT_B=BOT_B-10;
   }
}
void C()
{
   if(con==0)
   {
     BOT_C=BOT_C+10;
     switch(c[top_C])
     {
       case 10:setcolor(BLACK);rectangle(425,BOT_C-10,525,BOT_C-1);break;
       case  9:setcolor(BLACK);rectangle(430,BOT_C-10,520,BOT_C-1);break;
       case  8:setcolor(BLACK);rectangle(435,BOT_C-10,515,BOT_C-1);break;
       case  7:setcolor(BLACK);rectangle(440,BOT_C-10,510,BOT_C-1);break;
       case  6:setcolor(BLACK);rectangle(445,BOT_C-10,505,BOT_C-1);break;
       case  5:setcolor(BLACK);rectangle(450,BOT_C-10,500,BOT_C-1);break;
       case  4:setcolor(BLACK);rectangle(455,BOT_C-10,495,BOT_C-1);break;
       case  3:setcolor(BLACK);rectangle(460,BOT_C-10,490,BOT_C-1);break;
       case  2:setcolor(BLACK);rectangle(465,BOT_C-10,485,BOT_C-1);break;
       case  1:setcolor(BLACK);rectangle(470,BOT_C-10,480,BOT_C-1);break;
     }
   }
   else if(con==1)
   {
     switch(c[top_C])
     {
       case 10:setcolor(WHITE);rectangle(425,BOT_C-10,525,BOT_C-1);break;
       case  9:setcolor(WHITE);rectangle(430,BOT_C-10,520,BOT_C-1);break;
       case  8:setcolor(WHITE);rectangle(435,BOT_C-10,515,BOT_C-1);break;
       case  7:setcolor(WHITE);rectangle(440,BOT_C-10,510,BOT_C-1);break;
       case  6:setcolor(WHITE);rectangle(445,BOT_C-10,505,BOT_C-1);break;
       case  5:setcolor(WHITE);rectangle(450,BOT_C-10,500,BOT_C-1);break;
       case  4:setcolor(WHITE);rectangle(455,BOT_C-10,495,BOT_C-1);break;
       case  3:setcolor(WHITE);rectangle(460,BOT_C-10,490,BOT_C-1);break;
       case  2:setcolor(WHITE);rectangle(465,BOT_C-10,485,BOT_C-1);break;
       case  1:setcolor(WHITE);rectangle(470,BOT_C-10,480,BOT_C-1);break;
     }
     BOT_C=BOT_C-10;
   }
}
int procedure()
{
     switch(choice)
     {
	case 1:if(a[top_A]>b[top_B]&&top_B!=-1){error();return ' ';}
	       t=pop_A(); if(t!=' ') push_B(t); break;
	case 2:if(a[top_A]>c[top_C]&&top_C!=-1){error();return ' ';}
	       t=pop_A(); if(t!=' ') push_C(t); break;
	case 3:if(b[top_B]>a[top_A]&&top_A!=-1){error();return ' ';}
	       t=pop_B(); if(t!=' ') push_A(t); break;
	case 4:if(b[top_B]>c[top_C]&&top_C!=-1){error();return ' ';}
	       t=pop_B(); if(t!=' ') push_C(t); break;
	case 5:if(c[top_C]>a[top_A]&&top_A!=-1){error();return ' ';}
	       t=pop_C(); if(t!=' ') push_A(t); break;
	case 6:if(c[top_C]>b[top_B]&&top_B!=-1){error();return ' ';}
	       t=pop_C(); if(t!=' ') push_B(t); break;
	case 7:exit(0);
	default:error();
     }
}
void poles()
{
     setcolor(5);
     rectangle(100,200,530,225);  //Base
     gotoxy(17,14);printf("SOURCE             AUXILARY            DISTINATION");
     gotoxy(19,16);printf(" A                   B                   C");
     setcolor(8);
     rectangle(153,0,157,200);    //p 1
     rectangle(313,0,317,200);    //p 2
     rectangle(477,0,473,200);    //p 3
     setcolor(WHITE);
}
int error()
{
       gotoxy(20,17);sound(600);printf("This move is not allowed.Press ENTER to continue");delay(50);nosound();getch();
       gotoxy(20,17);            printf("                                                ");
}
char pop_A()
{
   if(top_A==-1)
   {
       error();return ' ';
   }
   temp=a[top_A];
   gotoxy(15,++X_top_A);printf(" ");con=0;  A();
   a[top_A]='9';
   --top_A;
   return temp;
}
char pop_B()
{
   if(top_B==-1)
   {
       error();return ' ';
   }
   temp=b[top_B];
   gotoxy(45,++X_top_B);printf(" ");con=0;   B();
   b[top_B]='9';
   top_B--;
   return temp;
}
char pop_C()
{
   if(top_C==-1)
   {
       error();return ' ';
   }
   temp=c[top_C];
   gotoxy(75,++X_top_C);printf(" ");con=0; C();
   c[top_C]='9';
   top_C--;
   return temp;
}
int push_A(char x)
{
    top_A++;
    if(va!=0)
      ++X_top_A;
    va++;
    if(top_A==disks)
    {
       top_A--;
       error();return ' ';
    }
    a[top_A]=x;
    if(a[top_A]=='9')
    {
       gotoxy(15,--X_top_A);printf(" ");con=0;A();
    }
    else
    {
       gotoxy(15,--X_top_A);printf("%d",a[top_A]);con=1;A();
    }
    X_top_A--;
    return 0;
}
int push_B(char x)
{
    top_B++;
    if(vb!=0)
      ++X_top_B;
    vb++;
    if(top_B==disks)
    {
       top_B--;
       error();return ' ';
    }
    b[top_B]=x;
    if(b[top_B]=='9')
    {
       gotoxy(45,--X_top_B);printf(" ");  con=0;B();
    }
    else
    {
       gotoxy(45,--X_top_B);printf("%d",b[top_B]);  con=1;B();
    }
    --X_top_B;
    return 0;
}
int push_C(char x)
{
    top_C++;
    if(vc!=0)
      ++X_top_C;
    vc++;
    if(top_C==disks)
    {
       top_C--;
       error();return ' ';
    }
    c[top_C]=x;
    if(c[top_C]=='9')
    {
       gotoxy(75,--X_top_C);printf(" ");con=0;C();
    }
    else
    {
       gotoxy(75,--X_top_C);printf("%d",c[top_C]);con=1;C();
    }
    --X_top_C;
    if(top_C==disks-1)
    {
       gotoxy(30,17);sound(1000);printf("You won the game TOWERS OF HANOI");delay(50);nosound();getch();
       gotoxy(30,17);textcolor(BLACK);printf("                                ");
       closegraph();exit(0);
    }
    return 0;
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
void ask()
{
    gotoxy(1,20);
    printf("To move the Disk from ONE Tower to ANOTHER Tower,\n");
    printf("1.A -> B,\n");
    printf("2.A -> C,\n");
    printf("3.B -> A,\n");
    printf("4.B -> C,\n");
    printf("5.C -> A,\n");
    printf("6.C -> B,\n");
    printf("7.EXIT\n");
    printf("Enter your choice : \b");
    scanf("%d",&choice);
}