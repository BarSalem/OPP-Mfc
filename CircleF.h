#pragma once
#include "Figure.h"

class CircleF :public Figure
{
	DECLARE_SERIAL(CircleF)
	int radius;
	CPoint center;
	CircleF() {}
	CircleF(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	int Area();
	bool isInside(const CPoint& p)const;
};
