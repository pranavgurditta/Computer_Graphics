#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

void kite(int i)
{
	/* /\ */
	line(150+i,100+i,100+i,160+i);
	line(150+i,100+i,200+i,160+i);
	
	/* \/ */
	line(100+i,160+i,150+i,210+i);
	line(200+i,160+i,150+i,210+i);
	
	/* -|- */
	line(100+i,160+i,200+i,160+i);
	line(150+i,100+i,150+i,210+i);
	
	// small triangle
	line(150+i,210+i,130+i,230+i);
	line(150+i,210+i,170+i,230+i);
	line(130+i,230+i,170+i,230+i);
	
	// Kite Thread
	int x[4],y[4];
	x[0] = 150+i;  y[0] = 210+i;
	x[1] = 200+i;  y[1] = 250+i;
	x[2] = 350+i;  y[2] = 130+i;
	x[3] = 500+i;  y[3] = 500+i;
	
	for(double t=0;t<=1;t+=0.0005)
	{
		double xt = pow(1-t,3) * x[0] + 3*t*pow(1-t,2) *x[1] +
			    3*t*t*(1-t)*x[2] + pow(t,3)*x[3];

		double yt = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] +
				   3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];

		putpixel(xt,yt,WHITE);
	}
}


void main()
{
	
	int gmode,gdriver=DETECT;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	clrscr();
	for(int k=0;k<2;k++)
	{
		if(kbhit())
		   return;
		for(int i=0;i<61 && !kbhit();i++)
		{
		    kite(i);

		    if(i>=60)
		    {
			for(int j=0;j<60 && !kbhit();j++)
			{
				kite(i-j);
				delay(120);
				cleardevice();
			}
		    }

		    delay(120);
		    cleardevice();
		}
	}

	getch();
	closegraph();
}
