#pragma once
#include "Figure.h"
#include "LineF.h"

class NorTriangleF :public LineF
{
	DECLARE_SERIAL(NorTriangleF)

	NorTriangleF() {}
	NorTriangleF(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	int Area();
};
