#include<cmath>
#include<iostream>
using namespace std;

class Points
{
	int x;
	int y;
public:
        Points(int,int);
	Points();
	void Set(int, int);
	friend float min(float,Points,Points);
	friend float closestPair(int, Points*);
};

Points::Points(int a, int b)
{
	x=a;
	y=b;
}

float closestPair(int n,Points* p)
{
	float d=999.99;
        int c,e;
        Points a,b;
	for( int i=0; i<n-1;i++)
	{
	  for ( int j =i+1; j<n; j++)
	  {
                  c=d; 
		  d= min(d,p[i],p[j]);
                  e=d;
                  if(c>e)
                  {
                    a.x=p[i].x;
                    a.y=p[i].y;
                    b.x=p[j].x;
                    b.y=p[j].y;
                  }
	  }
	}
        cout<<"\nClosest pairs are"<<"( "<<a.x<<","<<a.y<<" )"<<" and "<<"( "<<b.x<<","<<b.y<<" )"<<"\n";
	return d;
}

Points::Points()
{
	x=0;
	y=0;
}

void Points::Set(int a, int b)
{
	x=a;
	y=b;
}

float min(float min,Points p1,Points p2)
{
	float x= float(sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)));
	if(min>x)
	   min=x;
	return min;
}

int main()
{
	int n,x,y;
	cout<<"\t ~~~~~ Closest pair implementation using C++ ~~~~~\n";
	cout<<"Enter how many points U like to enter: ";
	cin>>n;
	Points *p= new Points[n];
	for (int i=0; i<n; i++)
	{
		cout<<"\nEnter point "<<i+1<<"\n";
		cin>>x;
		cin>>y;
		p[i].Set(x,y);
	}
	float distance=closestPair(n,p);
	cout<<"Closest pair's distance is ";
	cout<<distance<<"\n";
}

