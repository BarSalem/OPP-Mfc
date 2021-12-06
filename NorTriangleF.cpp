#include "stdafx.h"
#include "TriangleF.h"
#include "LineF.h"
#include "pch.h"

IMPLEMENT_SERIAL(NorTriangleF, CObject, 1)

NorTriangleF::NorTriangleF(CPoint p1, CPoint p2) :LineF(p1, p2) {}

void NorTriangleF::Draw(CDC* dc) const
{
	CPoint p1 = LineF::getP1();
	CPoint p2 = LineF::getP2();
	CPoint temp(p1.x, p2.y);
	CPoint other((p2.x - 2*(p2.x-p1.x)), p2.y);
	dc->MoveTo(p1);
	dc->LineTo(p2);
	dc->LineTo(other);
	dc->LineTo(p1);
}

int NorTriangleF::Area()
{
	CPoint p1 = LineF::getP1();
	CPoint p2 = LineF::getP2();
	int height, length;
	height = p1.y - p2.y;
	length = (p2.x - 2 * (p2.x - p1.x));
	if (height * length < 0)
	{
		return height * length / (2 * -37.7952755906* 37.7952755906);
	}
	else
		return height * length / (2 * -37.7952755906 * 37.7952755906);
}
