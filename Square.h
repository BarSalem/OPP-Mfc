#pragma once
#include "Figure.h"

class SquareF :public LineF
{
	DECLARE_SERIAL(SquareF)
public:
	SquareF(){}
	SquareF(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};
