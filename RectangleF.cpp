#include "stdafx.h"
#include "RectangleF.h"
#include "pch.h"

IMPLEMENT_SERIAL(RectangleF,CObject,1)

RectangleF::RectangleF(CPoint p1, CPoint p2):Figure(p1,p2) {}