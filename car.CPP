#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void car(int i,int color)
{
	setcolor(color);
	/*circle(50,40,25);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(50,40,15);*/	//To color boundary. 15->WHITE
       //	for(int i=0;i<700;i++)
	//int i=0;
	{
		line(-50,250,750,250);
		line(100+i,200,150+i,200);
		line(80+i,230,100+i,200);
		line(150+i,200,170+i,230);
		line(60+i,230,80+i,230);
		line(170+i,230,190+i,230);
		line(60+i,230,60+i,240);
		line(190+i,230,190+i,240);
		line(60+i,240,88+i,240);
		arc(99+i,240,0,180,10);
		line(110+i,240,133+i,240);
		arc(143+i,240,0,180,10);
		line(153+i,240,190+i,240);
		circle(99+i,241,7);
		circle(143+i,241,7);
		line(120+i,210,120+i,220);
		line(127+i,210,127+i,220);
		line(120+i,210,105+i,220);
		line(127+i,210,142+i,220);
		line(105+i,220,120+i,220);
		line(127+i,220,142+i,220);
		delay(20);
		//cleardevice();
	}
	//line();
}
void main()
{
	clrscr();
	int i=0;
	int gd=DETECT,gm;
	char ch='g';
	initgraph(&gd,&gm,"C:\\TURBOC3\\BIN");
	//line();
	circle(50,40,25);
       //	circle(,25);
       //	circle(,25);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(50,40,15);	//To color boundary. 15->WHITE
	while(1)
	{
	       //	car(i,0);
		while(!kbhit())
		{
		car(i,0);
			if(ch=='r')
			{
				setfillstyle(SOLID_FILL,RED);
				floodfill(50,40,15);
			}
			if(ch=='y')
			{
				setfillstyle(SOLID_FILL,YELLOW);
				floodfill(50,40,15);
			 }
			if(ch=='g')
			{
				setfillstyle(SOLID_FILL,GREEN);
				floodfill(50,40,15);
				i++;
			}
			car(i,15);
			delay(50);
		}
	       //	car(i,15);
		ch=getch();
		if(ch==13)
		{
			break;
		}
	}
       //	car();//i);
	getch();
	closegraph();
}
