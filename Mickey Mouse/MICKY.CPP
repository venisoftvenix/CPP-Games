#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
void micky();
void venky();
void table();
void main()
{
  micky();
  venky();
  table();
  getch();
  closegraph();
}
void table()
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
     setcolor(14);
     //left shoe
     ellipse(210,395,153,200,40,70);
     ellipse(192,394,0,78,40,50);
     ellipse(204,404,95,140,40,60);
     ellipse(272,394,180,245,40,60);
     ellipse(282,404,160,236,30,60);
     ellipse(200,385,0,90,53,40);
     ellipse(226,403,190,280,55,60);
     ellipse(175,454,313,390,90,13);
     line(220,460,240,430);
     //right shoe
     ellipse(440,340,290,84,60,90);  //4 4 l
     ellipse(469,314,79,230,20,50);   //4 5 l
     ellipse(476,354,180,290,20,50);
     line(498,360,457,360);
     ellipse(454,370,155,281,29,55);
     ellipse(450,305,94,229,35,55);
     //book
     line(368,230,364,360);
     line(370,230,366,360);
     line(372,230,368,360);
     ellipse(370,226,0,360,3,3);
     line(367,227,435,164);
     line(374,227,441,164);
     line(367,360,415,317);
     ellipse(371,243,300,100,20,20);  //c u
     ellipse(397,273,140,265,20,20);  //c l
     ellipse(422,335,97,120,50,50);  //c un
     ellipse(447,213,110,230,15,50);  //end
     ellipse(438,165,0,360,3,3);
     //fingures
     line(425,255,440,245);
     line(425,248,440,238);
     line(425,241,438,233);
     line(425,234,436,227);
     ellipse(440,242,280,75,3,3);
     ellipse(437,230,280,75,3,3);
     ellipse(439,236,280,75,2,2);
     ellipse(440,242,280,75,3,3);
     setfillstyle(1,5);
     fillellipse(426,244,3,2);
     fillellipse(425,237,3,2);
     fillellipse(426,251,3,2);
     //nose
     arc(390,197,99,150,60);
     setfillstyle(1,9);
     fillellipse(385,128,8,15);

     //legs
     ellipse(180,237,292,302,200,200);
     ellipse(470,247,235,260,200,170);
     ellipse(330,516,67,128,70,140);
     ellipse(470,207,240,257,200,170);
     ellipse(180,200,292,296,200,200);
     //ellipse(180,200,0,360,300,300);

     //stomach
     ellipse(345,307,205,10,20,25);
     ellipse(290,265,25,200,15,15);
     ellipse(318,255,35,200,15,15);
     ellipse(298,380,380,65,75,150);
     line(275,270,285,280);
     //hands
     ellipse(470,93,225,240,200,170);
     ellipse(251,295,145,290,20,9);
     ellipse(288,290,180,220,40,4);
     line(260,218,232,295);
     line(260,255,247,290);
     line(342,260,367,270);
     line(262,255,273,265);
     //hair
     setcolor(BROWN);
     setfillstyle(1,BROWN);
     fillellipse(235,140,20,20);
     fillellipse(233,170,15,15);
     fillellipse(220,155,5,9);
     fillellipse(218,164,2,2);
     fillellipse(216,146,2,3);
     fillellipse(235,115,10,10);
     fillellipse(225,122,5,5);
     fillellipse(265,115,30,30);
     fillellipse(244,105,10,10);
     fillellipse(278,91,21,10);
     fillellipse(269,155,10,20);
     fillellipse(239,180,12,20);
     fillellipse(250,149,15,20);
     fillellipse(230,181,10,10);
     fillellipse(218,155,5,15);
     fillellipse(223,127,5,5);
     fillellipse(228,114,5,5);
     fillellipse(236,105,5,5);
     sector(290,100,140,410,20,20);
     setfillstyle(1,RED);
     fillellipse(284,216,9,3);
     setcolor(BLACK);
     setfillstyle(1,BLACK);
     fillellipse(282,130,20,40);
     fillellipse(258,200,20,40);
     setcolor(WHITE);
     rectangle(0,0,639,478);

 /*    line(145,0,145,479);
     line(505,0,505,479);
     line(235,0,235,479);
     line(325,0,325,479);
     line(415,0,415,479);
     line(145,96,505,96);
     line(145,192,505,192);
     line(145,288,505,288);
     line(145,384,505,384);
  */   line(145,480,505,480);
     //first in last
     setcolor(14);
     setfillstyle(11,9);
     fillellipse(183,149,30,42);
     setfillstyle(11,9);
     fillellipse(260,48,30,35);

     arc(283,150,0,265,70);
     arc(320,150,200,365,65);   //3 3
     ellipse(283,180,170,310,25,40);  //2 3 l u

     line(260,218,232,295);
     //eyes
     ellipse(340,140,0,360,7,14);
     ellipse(320,155,0,360,7,14);
     setfillstyle(1,BLUE);
     fillellipse(342,147,3,5);
     fillellipse(322,162,3,5);
     //glouse
     ellipse(261,275,230,330,18,18);
     ellipse(290,297,30,150,18,18);
     ellipse(317,277,203,270,16,16);
     ellipse(309,299,280,410,16,8);
     ellipse(311,313,280,440,16,6);
     ellipse(307,278,220,290,60,40);
     //pen
     setcolor(1);
     setfillstyle(1,8);
     line(254,280,340,314);
     line(254,279,340,314);
     line(254,281,340,314);
     fillellipse(255,280,3,3);
     //l leg
     setcolor(14);
     ellipse(291,419,120,130,40,50);
     ellipse(242,324,290,360,60,60);
     line(255,171,263,171);
  /* while(!kbhit())
     {
	setfillstyle(1,12);
	fillellipse(320,155,7,14);
	delay(300);
	setfillstyle(1,BLACK);
	fillellipse(320,155,7,14);
	setfillstyle(1,BLUE);
	fillellipse(322,162,3,5);
	delay(300);
	ellipse(320,155,0,360,7,14);
	setfillstyle(1,BLUE);
	fillellipse(322,162,3,5);
     }*/
}
void micky()
{
   int i=0;
   while(i<=40)
   {
      i++;
      gotoxy(30,24);textcolor(14);cprintf("MICKY MOUSE");
      gotoxy(random(80),random(49));
      textcolor(random(16));
      cprintf("MICKY MOUSE");
      sound(random(8000));
      delay(100);
      clrscr();
   }
   nosound();
}
void venky()
{
   int i=0;
   while(i<=35)
   {
      i++;
      gotoxy(24,24);textcolor(14);cprintf("Programe by VENIGANDLA VENKATESH");
      gotoxy(random(80),random(49));
      textcolor(random(16));
      cprintf("MICKY MOUSE");
      sound(random(8000));
      delay(100);
      clrscr();
   }
   nosound();
}