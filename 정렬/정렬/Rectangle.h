#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Header.h"

class Rectangle
{
private :
	double h;
	double w;
	long double area;

public :
	Rectangle() {};
	Rectangle(double h, double w)
	{
		this->h = h;
		this->w = w;
		area = h*w;
	}
	~Rectangle() {};

	friend bool operator < (Rectangle &r1, Rectangle &r2);
	friend bool operator > (Rectangle &r1, Rectangle &r2);
	friend bool operator <=(Rectangle &r1, Rectangle &r2);
	friend bool operator >=(Rectangle &r1, Rectangle &r2);
	friend bool operator ==(Rectangle &r1, Rectangle &r2);
	friend ofstream& operator <<(ofstream &ofs, Rectangle &r);

};

bool operator < (Rectangle &r1, Rectangle &r2)
{
	if (r1.area < r2.area)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator > (Rectangle &r1, Rectangle &r2)
{
	if (r1.area > r2.area)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator <=(Rectangle &r1, Rectangle &r2)
{
	if (r1.area <= r2.area)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator >=(Rectangle &r1, Rectangle &r2)
{
	if (r1.area >= r2.area)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator ==(Rectangle &r1, Rectangle &r2)
{
	if (r1.area == r2.area)
	{
		return true;
	}
	else
	{
		return false;
	}
}
ofstream& operator <<(ofstream &ofs, Rectangle &r)
{
	ofs << r.area;

	return ofs;
}

#endif
