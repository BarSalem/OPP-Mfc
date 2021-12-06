#include "stdafx.h"
#include "TriangleF.h"
#include "LineF.h"
#include "pch.h"

IMPLEMENT_SERIAL(TriangleF, CObject, 1)

TriangleF::TriangleF(CPoint p1,CPoint p2) :LineF(p1,p2) {}

void TriangleF::Draw(CDC* dc)const
{	
	CPoint p1 = LineF::getP1();
	CPoint p2 = LineF::getP2();
	CPoint temp(p1.x, p2.y);
	dc->MoveTo(p1);
	dc->LineTo(p2);
	dc->LineTo(temp);
	dc->LineTo(p1);
}

int TriangleF::Area()
{
	int height, length;
	height = p2.y - p1.y;
	length = p2.x - p1.x;
	if (height * length < 0)
		return (height * length) / -(37.7952755906 * 37.7952755906 * 2);
	else 
		return (height * length) / (37.7952755906 *37.7952755906 * 2);
}