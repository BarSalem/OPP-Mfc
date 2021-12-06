#include "stdafx.h"
#include "LineF.h"
#include "pch.h"
#include <math.h>

IMPLEMENT_SERIAL(LineF, CObject, 1)

LineF::LineF(CPoint p1, CPoint p2) :Figure(p1, p2) {}

void LineF::Draw(CDC* dc)const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->MoveTo(p1);
	dc->LineTo(p2);
}

int LineF::Area()
{
	CPoint p1, p2;
	p1 = this->getP1();
	p2 = this->getP2();
	double result = pow(((double)p1.x - (double)p2.x), 2) + pow(((double)p1.y - (double)p2.y), 2);
	if(result<0)
		return sqrt(result)/ (2 * -37.7952755906 * 37.7952755906);
	else 
		return sqrt(result) / (2 * 37.7952755906 * 37.7952755906);
}