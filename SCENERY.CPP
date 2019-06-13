#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void road()
{
    int xMax=getmaxx();
    int yMax=getmaxy();
    line(0,yMax-100,xMax,yMax-100);
    line(0,yMax-150,xMax,yMax-150);

    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(1,yMax-125,WHITE);

    setcolor(YELLOW);
    setlinestyle(DASHED_LINE,0,2);
    line(0,yMax-125,xMax,yMax-125);

    setcolor(WHITE);
    setlinestyle(SOLID_LINE,0,1);
}

void car(int i=0)
{
    //int xMax=getmaxx();
    int yMax=getmaxy()+15;

    //Left-Verticle line
    line(0+i,yMax-200,0+i,yMax-180);

    //Left-low slant
    line(0+i,yMax-200,23+i,yMax-210);

    //Left-upper slant
    line(23+i,yMax-210,42+i,yMax-228);

    //Left-window
    line(38+i,yMax-211,49+i,yMax-223);
    line(38+i,yMax-211,73+i,yMax-211);
    line(49+i,yMax-223,73+i,yMax-223);
    line(73+i,yMax-211,73+i,yMax-223);

    //Right window
    line(119+i,yMax-211,108+i,yMax-223);
    line(119+i,yMax-211,77+i,yMax-211);
    line(108+i,yMax-223,77+i,yMax-223);
    line(77+i,yMax-211,77+i,yMax-223);

    //Top-Horizontal
    line(42+i,yMax-228,112+i,yMax-228);

    //Right-upper slant
    line(112+i,yMax-228,132+i,yMax-210);

    //Right-low slant
    line(132+i,yMax-210,170+i,yMax-195);

    //Right-vertical
    line(170+i,yMax-195,170+i,yMax-180);

    //Bottom-horizontal right wheel
    line(170+i,yMax-180,145+i,yMax-180);

    //Bottom-Horizontal left wheel
    line(0+i,yMax-180,25+i,yMax-180);

    //Left wheel
    arc(42+i,yMax-180,0,180,17);
    circle(42+i,yMax-180,15);
    circle(42+i,yMax-180,3);

    //Right wheel
   arc(127+i,yMax-180,0,180,17);
   circle(127+i,yMax-180,15);
   circle(127+i,yMax-180,3);

   //Bottom-Horizontal
   line(59+i,yMax-180,110+i,yMax-180);

   setfillstyle(SOLID_FILL,RED);
   floodfill(5+i,yMax-190,WHITE);
}

void mountains()
{
    int xMax=getmaxx();

    for(int i=0;i<xMax;i+=120)
    {
       line(i,100,i+60,25);
       line(i+60,25,i+120,100);
    }

    line(0,102,xMax,102);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(0,101,WHITE);

    setcolor(BLACK);
    line(0,102,xMax,102);

}

void sun()
{
    circle(240,30,20);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(240,30,WHITE);
    line(240,50,240,62);
    line(240,10,240,0);
    line(260,30,272,30);
    line(220,30,208,30);
    line(228,17,215,9);
    line(255,43,265,49);
    line(228,43,215,49);
    line(255,17,265,9) ;

}

void tree(int i=0,int j=0)
{

    arc(200+i,200+j,260,90,10);
    arc(185+i,190+j,0,180,14);
    arc(171+i,200+j,90,282,10);

   // arc(171,210,140,280,8);

    arc(205+i,219+j,130,222,12);
    arc(166+i,219+j,328,54,12);

    line(175+i,210+j,196+i,210+j);
    line(175+i,227+j,195+i,227+j);

    setfillstyle(SOLID_FILL,GREEN);
    floodfill(200+i,200+j,WHITE);

    setfillstyle(SOLID_FILL,BROWN);
    floodfill(180+i,220+j,WHITE);

    setcolor(GREEN);
    line(175+i,210+j,196+i,210+j);

    setcolor(BROWN);
    line(175+i,227+j,195+i,227+j);

    setcolor(WHITE);

}

void house(int i=0,int j=0,int col=LIGHTRED)
{   // /\
    line(i,j+20,i+20,j);
    line(i+20,j,i+40,j+20);

    //|_|
    line(i,j+20,i,j+50);
    line(i+40,j+20,i+40,j+50);
    line(i,j+50,i+40,j+50);   //__

    //  __
    //  ___\
    line(i+80,j,i+100,j+20);
    line(i+100,j+20,i+40,j+20);
    line(i+80,j,i+20,j);

    setfillstyle(BKSLASH_FILL,BROWN);
    floodfill(i+50,j+15,WHITE);

    // ___|
    line(i+100,j+20,i+100,j+50);
    line(i+100,j+50,i+40,j+50);

    //
    line(i+10,j+27,i+10,j+50);
    line(i+30,j+27,i+30,j+50);
    line(i+10,j+27,i+30,j+27);
    circle(i+26,j+37,1.5);
    setfillstyle(INTERLEAVE_FILL,BROWN);
    floodfill(i+15,j+35,WHITE);


    setfillstyle(HATCH_FILL,col);
    floodfill(i+5,j+45,WHITE);

    setfillstyle(HATCH_FILL,col);
    floodfill(i+50,j+40,WHITE);
}

void stones()
{
   int x= getmaxx();
   int y= getmaxy();

   ellipse(x-130,y-50,0,360,15,10);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(x-130,y-50,WHITE);

   ellipse(x-150,y-48,53,329,13,8);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(x-150,y-48,WHITE);

}

void main()
{
  int gdriver=DETECT,gmode;
  clrscr();
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
  car();
  sun();
  road();
  stones();
  for(int i=-140;i<=1000;i+=70)
    tree(i,37);
  house(150,130);
  house(290,145,MAGENTA);
  house(420,135,CYAN);
  house(10,145,CYAN);
  house(538,145,YELLOW);
  mountains();
  getch();
  closegraph();
}