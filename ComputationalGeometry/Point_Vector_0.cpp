#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int M=1005;

/*================================*\
|                                  |
|  0.basic                         |
|                                  |
\*================================*/

const double EPS=1e-8;
const double PI=acos(-1.0);

inline int sgn(double x)
{
	return (x>EPS)-(x<-EPS);
}

inline double sqr(double x)
{
	return x*x;
}

/*================================*\
|                                  |
|  1.Point & Vector                |
|                                  |
\*================================*/

struct Point
{
	double x,y;
	Point(double x=0,double y=0)
		:x(x),y(y){}
	bool operator<(const Point &B) const
	{
		//return sgn(x-B.x) ? x<B.x : y<B.y;
		return x==B.x ? y<B.y : x<B.x;
	}
	bool operator==(const Point &B) const
	{
		return !sgn(x-B.x) && !sgn(y-B.y);
	}
	Point operator+(const Point &B) const
	{
		return Point(x+B.x,y+B.y);
	}
	Point operator-(const Point &B) const
	{
		return Point(x-B.x,y-B.y);
	}
	Point operator*(double a) const
	{
		return Point(x*a,y*a);
	}
	Point operator/(double a) const
	{
		return Point(x/a,y/a);
	}
	Point operator-() const
	{
		return Point(-x,-y);
	}
	friend double dot(const Point &A,const Point &B) //dot prodect
	{
		return A.x*B.x+A.y*B.y;
	}
	friend double det(const Point &A,const Point &B) //cross prodect
	{
		return A.x*B.y-A.y*B.x;
	}
	friend double dis(const Point &A,const Point &B)
	{
		return (A-B).length();
	}
	double dis(const Point &B)
	{
		return (*this-B).length();
	}
	double det3(const Point &B,const Point &C) const
	{
		// return det(B-*this,C-*this);
		return (B.x-x)*(C.y-y)-(B.y-y)*(C.x-x);
	}
	double dot3(const Point &B,const Point &C) const
	{
		// return dot(B-*this,C-*this);
		return (B.x-x)*(C.x-x)+(B.y-y)*(C.y-y);
	}

	double polar() //rad
	{
		return atan2(y,x);
	}
	double length()
	{
		return sqrt(sqr(x)+sqr(y));
	}
	Point normal() // normal vector
	{
		return Point(-y,x);
	}
	Point unit() // unit vector
	{
		double l=length();
		return Point(x/l,y/l);
	}
	Point rotate(double r) // rotate r rad around origin
	{
		return Point(x*cos(r)-y*sin(r),x*sin(r)+y*cos(r));
	}
	Point rotate(const Point &o,double r) // rotate r rad around o
	{
		return (*this-o).rotate(r)+o;
	}
	Point up()
	{
		Point p(x,y);
		if(y<0)
			x=-x,y=-y;
		return p;
	}
	Point right()
	{
		Point p(x,y);
		if(x<0)
			x=-x,y=-y;
		return p;
	}
};
// typedef Point Vector;

int main()
{
	return 0;
}