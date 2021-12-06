#pragma once
#include "Figure.h"
#include "LineF.h"

class TriangleF :public LineF
{
	DECLARE_SERIAL(TriangleF)

	TriangleF(){}
	TriangleF(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	int Area();
};
