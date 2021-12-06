#include "stdafx.h"
#include "Square.h"
#include "pch.h"

IMPLEMENT_SERIAL(SquareF, CObject, 1)

SquareF::SquareF(CPoint p1, CPoint p2) :LineF(p1, p2) {}

void SquareF::Draw(CDC* dc) const
{
	CPoint p1 = SquareF::getP1();
	CPoint p2 = SquareF::getP2();
	CPoint temp1,temp2,temp3,temp4;
	temp1=p2-p1;
	temp2 = p2.y - p1.y;
	dc->MoveTo(p1);
	dc->LineTo(p2.x, temp1.y);
	dc->LineTo(p2.x, p2.y);
	dc->LineTo(p1.x, p2.y);
	dc->LineTo(p1.x, p1.y);
}


