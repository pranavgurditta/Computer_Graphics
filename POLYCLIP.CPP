#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define ROUND(a) ((int)(a+0.5))

struct Node{
	int x;
	int y;
};

class PolyClip
{
	int winL,winR,winT,winB;
	Node vertices[20];
	int n;
	public:
		void input();
		void initialize();
		void left();
		void right();
		void top();
		void bottom();
		void draw();
		void putPixel(int x,int y,int COLOR);
		void drawline();
};

void PolyClip::input()
{
	clrscr();
	cout<<"\n\t\tFrame Window's co-ordinate";
	cout<<"\nTop-Right co-ordinate(x,y):";
	cin>>winR>>winT;
	cout<<"\nBottom-Left co-ordinate(x,y):";
	cin>>winL>>winB;
	cout<<"\n\nEnter the number of nodes in polygon:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n\tNode "<<(i+1)<<" :";
		cin>>vertices[i].x>>vertices[i].y;
	}
	draw();
	getch();
	left();
	draw();
	getch();
	top();
	draw();
	getch();
	right();
	draw();
	getch();
	bottom();
	draw();
}

void PolyClip::putPixel(int x,int y,int COLOR=WHITE)
{
   int maxx_2=getmaxx()/2;
   int maxy_2=getmaxy()/2;
   putpixel(x+maxx_2,maxy_2-y,COLOR);
}

void PolyClip::initialize()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
}

void PolyClip::drawline()
{
   int maxx=getmaxx();
   int maxy=getmaxy();
   int maxx_2=maxx/2;
   int maxy_2=maxy/2;
   line(0,maxy_2,maxx,maxy_2);
   line(maxx_2,0,maxx_2,maxy);
}

void PolyClip::draw()
{
	int x_min=winL,x_max=winR,y_min=winB,y_max=winT;
	int maxx_2=getmaxx()/2;
	int maxy_2=getmaxy()/2;
	clrscr();
	initialize();
	drawline();
	setcolor(5);
    line(x_min+maxx_2,maxy_2-y_min,x_max+maxx_2,maxy_2-y_min);
    line(x_min+maxx_2,maxy_2-y_min,x_min+maxx_2,maxy_2-y_max);
    line(x_min+maxx_2,maxy_2-y_max,x_max+maxx_2,maxy_2-y_max);
    line(x_max+maxx_2,maxy_2-y_max,x_max+maxx_2,maxy_2-y_min);

	setcolor(WHITE);
	for(int i=0;i<n-1;i++)
		line(vertices[i].x+maxx_2,maxy_2-vertices[i].y,vertices[i+1].x+maxx_2,maxy_2-vertices[i+1].y);
	line(vertices[i].x+maxx_2,maxy_2-vertices[i].y,vertices[0].x+maxx_2,maxy_2-vertices[0].y);
}

void PolyClip::left()
{
	Node v[20];
	int j=0;
	for(int i=0;i<n;i++)
	{
		int n1=0,n2=0;
		if(vertices[i].x<winL)
			n1=1;
		if(vertices[(i+1)%n].x<winL)
			n2=1;
		
		//Both vertex are inside,save just the second
		if(n1==0 && n2==0)
			v[j++]=vertices[(i+1)%n];

		//vertex1:outside vertex2:inside => pt of intersection & second pt is saved
		else if(n1==1 && n2==0)
		{
			float m =(float) (vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.x = winL;
			n1.y = ROUND(m*(n1.x-vertices[i].x)+vertices[i].y);
			v[j++] = n1;
			v[j++] = vertices[(i+1)%n];
		}
		
		//vertex1: inside vertex2:outside => pt of intersection
		else if(n1==0 && n2==1)
		{
			float m = (float)(vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.x = winL;
			n1.y = ROUND(m*(n1.x-vertices[i].x)+vertices[i].y);
			v[j++] = n1;
		}	
		
	}
	
	for(i=0;i<j;i++)
	   vertices[i]=v[i];
	n = j;
}

void PolyClip::right()
{
	Node v[20];
	int j=0;
	for(int i=0;i<n;i++)
	{
		int n1=0,n2=0;
		if(vertices[i].x>winR)
			n1=1;
		if(vertices[(i+1)%n].x>winR)
			n2=1;
	       //	cout<<n1<<" "<<n2;
		//Both vertex are inside,save just the second
		if(n1==0 && n2==0)
			v[j++]=vertices[(i+1)%n];

		//vertex1:outside vertex2:inside => pt of intersection & second pt is saved
		else if(n1==1 && n2==0)
		{
			float m =(float) (vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.x = winR;
			n1.y = ROUND(m*(n1.x-vertices[i].x)+vertices[i].y);
			v[j++] = n1;
			v[j++] = vertices[(i+1)%n];
		}

		//vertex1: inside vertex2:outside => pt of intersection
		else if(n1==0 && n2==1)
		{
			float m = (float)(vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.x = winR;
			n1.y = ROUND(m*(n1.x-vertices[i].x)+vertices[i].y);
			v[j++] = n1;
		}

	}

	for(i=0;i<j;i++)
	{
	   vertices[i]=v[i];
	}
	n = j;
}


void PolyClip::bottom()
{
	Node v[20];
	int j=0;
	for(int i=0;i<n;i++)
	{
		int n1=0,n2=0;
		if(vertices[i].y<winB)
			n1=1;
		if(vertices[(i+1)%n].y<winB)
			n2=1;
		
		//Both vertex are inside,save just the second
		if(n1==0 && n2==0)
			v[j++]=vertices[(i+1)%n];

		//vertex1:outside vertex2:inside => pt of intersection & second pt is saved
		else if(n1==1 && n2==0)
		{
			float m =(float) (vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.y = winB;
			n1.x = ROUND((n1.y-vertices[i].y)/m+vertices[i].x);
			v[j++] = n1;
			v[j++] = vertices[(i+1)%n];
		}
		
		//vertex1: inside vertex2:outside => pt of intersection
		else if(n1==0 && n2==1)
		{
			float m = (float)(vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.y = winB;
			n1.x = ROUND((n1.y-vertices[i].y)/m + vertices[i].x);
			v[j++] = n1;
		}	
		
	}
	
	for(i=0;i<j;i++)
	   vertices[i]=v[i];
	n = j;
}

void PolyClip::top()
{
	Node v[20];
	int j=0;
	for(int i=0;i<n;i++)
	{
		int n1=0,n2=0;
		if(vertices[i].y>winT)
			n1=1;
		if(vertices[(i+1)%n].y>winT)
			n2=1;
		
		//Both vertex are inside,save just the second
		if(n1==0 && n2==0)
			v[j++]=vertices[(i+1)%n];

		//vertex1:outside vertex2:inside => pt of intersection & second pt is saved
		else if(n1==1 && n2==0)
		{
			float m =(float) (vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.y = winT;
			n1.x = ROUND((n1.y-vertices[i].y)/m+vertices[i].x);
			v[j++] = n1;
			v[j++] = vertices[(i+1)%n];
		}
		
		//vertex1: inside vertex2:outside => pt of intersection
		else if(n1==0 && n2==1)
		{
			float m = (float)(vertices[(i+1)%n].y - vertices[i].y)/(vertices[(i+1)%n].x - vertices[i].x);
			Node n1;
			n1.y = winT;
			n1.x = ROUND((n1.y-vertices[i].y)/m + vertices[i].x);
			v[j++] = n1;
		}	
		
	}
	
	for(i=0;i<j;i++)
	   vertices[i]=v[i];
	n = j;
}

void main()
{
	clrscr();
	PolyClip p;
	p.initialize();
	p.input();
	getch();
}