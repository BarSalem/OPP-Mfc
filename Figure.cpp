#include "stdafx.h"  
#include "Figure.h"
#include "pch.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)

Figure::Figure(CPoint p1, CPoint p2) :p1(p1), p2(p2) 
{
	this->col = RGB(255, 255, 255);
	this->width = 10;
}

CPoint Figure::getCenter()
{
	CPoint temp;
	temp.x = (p1.x + p2.x) / 2;
	temp.y = (p1.y + p2.y) / 2;
	return temp;
}

bool Figure::isInside(const CPoint& P) const
{
	return (p1.x <= P.x && P.x <= p2.x || p1.x >= P.x && P.x >= p2.x) &&
		(p1.y <= P.y && P.y <= p2.y || p1.y >= P.y && P.y >= p2.y);
}
void Figure::Shift(CPoint move)
{
	p1 = p1 + move;
	p2 = p2 + move;
}

int Figure::Area()
{
	int height,length;
	height = p2.y - p1.y;
	length = p2.x - p1.x;
	if (height < 0 || length < 0)
	{
		return (height * length) / (37.7952755906 * 37.7952755906);
	}
	else
		return (height * length)/ (37.7952755906*37.7952755906);
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << p1;
		ar << p2;
		ar << col;
	}
	else
	{
		ar >> p1;
		ar >> p2;
		ar >> col;
	}
}
