#include "stdafx.h"
#include "CircleF.h"
#include "pch.h"

IMPLEMENT_SERIAL(CircleF, CObject, 1)

CircleF::CircleF(CPoint p1, CPoint p2) :Figure(p1, p2)
{
	radius = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}

void CircleF::Draw(CDC* dc)const
{
	CPoint p1= getP1();
	CPoint p2 = getP2();
	CPoint temp;
	int radius = sqrt(((p2.x - p1.x) * (p2.x - p1.x))
		+ ((p2.y - p1.y) * (p2.y - p1.y)));
	if (temp.x < 0) temp.x *= -1;
	if (temp.y < 0) temp.y *= -1;
	dc->Ellipse(p1.x - radius,p1.y - radius,p1.x + radius,p1.y + radius);
}

int CircleF::Area()
{
	int Radius = p1.x - p2.x;
	if (Radius < 0)
	{
		return Radius * 3.14 / -37.7952755906;
	}
	return Radius *3.14 / 37.7952755906;
}

bool CircleF::isInside(const CPoint& P)const
{
	int radius = sqrt(((p2.x - p1.x) * (p2.x - p1.x))
		+ ((p2.y - p1.y) * (p2.y - p1.y)));
	int tempx = P.x - p1.x;
	int tempy = P.y - p1.y;
	if (tempy < 0) tempy *= -1;
	if (tempx < 0) tempx *= -1;
	if (tempx < radius && tempy < radius) return true;
	return false;
}
