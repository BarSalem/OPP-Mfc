#pragma once
#include "stdafx.h"
#include "pch.h"

class Figure :public CObject
{
	DECLARE_SERIAL(Figure)

	CPoint p1;
	CPoint p2;
	COLORREF col;
	int width;

public:
	void setP1(CPoint p) { p1 = p; }
	void setP2(CPoint p) { p2 = p; }
	CPoint getP1()const { return p1; }
	CPoint getP2()const { return p2; }
	void setCol(COLORREF color) { this->col = color; }
	void setWidth(int newWidth) { this->width = newWidth; }
	CPoint getCenter();
	//void setColor(COLORREF color) { this->col = color; }
	Figure(){}
	Figure(CPoint p1, CPoint p2);
	~Figure() {}
	virtual void Draw(CDC* dc) const
	{
		dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
	}
	void Serialize(CArchive& ar);
	virtual void Redefine(CPoint pStart, CPoint pEnd) { p1 = pStart; p2 = pEnd; }
	virtual bool isInside(const CPoint& p)const;
	virtual void Shift(CPoint move);
	virtual int Area();
	//virtual void turn45Deg();
};
