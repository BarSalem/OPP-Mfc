#include "stdafx.h"
#include "EllipseF.h"
#include "pch.h"

IMPLEMENT_SERIAL(EllipseF,CObject,1)

EllipseF::EllipseF(CPoint p1,CPoint p2):Figure(p1,p2) {}
void EllipseF::Draw(CDC* dc)const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}

int EllipseF::Area()
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	int a, b;
	a = p2.x - p1.x;
	b = p2.y - p1.y;
	int Area = a * b * 3.14 / (37.7952755906 * 37.7952755906);
	if (Area < 0) return -1 * Area;
	else return Area;

}