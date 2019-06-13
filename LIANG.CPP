#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#define ROUND(x) ( (int)(x+0.5) )

class LiangBarsky
{
    int xMin,xMax,yMin,yMax;
    int xa,ya,xb,yb;
	int p[4],q[4];
    float t1,t2;
    public:
		void input(int,int,int,int);
		void initWindow(int,int,int,int);
		void clip();
		void output();
		void setParam();
		void checkLine();
		float max(float a,float b)
		{
		    if (a>b)
		       return a;
		    else
		       return b;
		}
		float min(float a,float b)
		{
		    if (a<b)
			return a;
		    else
			return b;
		}
};

//Output clipped line end points
void LiangBarsky::output()
{
    cout<<"("<<xa<<","<<ya<<"), ("<<xb<<","<<yb<<")";
}

//Initialize the line end points
void LiangBarsky::input(int xMin,int yMin,int xMax,int yMax)
{
    xa = xMin;
    ya = yMin;
    xb = xMax;
    yb = yMax;
    t1=0.0;
    t2=1.0;
}

//Initialize the window end points
void LiangBarsky::initWindow(int xa,int ya,int xb,int yb)
{
    xMin = xa;
    yMin = ya;
    xMax = xb;
    yMax = yb;
}

//Set parameter values
void LiangBarsky::setParam()
{
	p[0] = -(xb-xa);		q[0] = xa-xMin;
	p[1] = xb-xa;			q[1] = xMax-xa;
	p[2] = -(yb-ya);		q[2] = ya-yMin;
	p[3] = yb-ya;			q[3] = yMax-ya;

	for(int i=0;i<4;i++)
	{
		float t = (float)q[i]/p[i]  ;
		//cout<<p[i]<<" "<<t;
		if(p[i]<0)
			t1 = max(t1,t);
		else
			t2 = min(t2,t);
	       //	cout<<t1<<","<<t2<<"\n";
	}

}

//Check the nature of line
void LiangBarsky::checkLine()
{
	setParam();
	if(t1>t2)
		cout<<"Line is completely out of the window";
	else
	{
		cout<<"\nEnd points of line after clipping:";
		int x1,x2,y1,y2;

		x1 = ROUND(xa+t1*(xb-xa));
		y1 = ROUND(ya+t1*(yb-ya));

		x2 = ROUND(xa+t2*(xb-xa));
		y2 = ROUND(ya+t2*(yb-ya));

		xa=x1;
		xb=x2;
		ya=y1;
		yb=y2;

		output();
	}
}

void main()
{
   clrscr();
   LiangBarsky s;
   int xa,ya,xb,yb,xMin,yMin,xMax,yMax;
   cout<<"\nEnter windows co-ordinate:";
   cout<<"\n\tX-min:";
   cin>>xMin;
   cout<<"\n\tY-min:";
   cin>>yMin;
   cout<<"\n\tX-max:";
   cin>>xMax;
   cout<<"\n\tY-max:";
   cin>>yMax;
   s.initWindow(xMin,yMin,xMax,yMax);
   cout<<"\nEnter end points of line:";
   cout<<"\n\tX co-ordinate of first point:";
   cin>>xa;
   cout<<"\n\tY co-ordinate of first point:";
   cin>>ya;
   cout<<"\n\tX co-ordinate of second point:";
   cin>>xb;
   cout<<"\n\tY co-ordinate of second point:";
   cin>>yb;
   s.input(xa,ya,xb,yb);
   s.checkLine();
   getch();
}