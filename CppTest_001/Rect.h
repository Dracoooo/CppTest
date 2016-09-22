#pragma once
class Rect
{
public:
	//TODO:是否可用共同体节省内存空间
	float length;
	float width;
	Rect();
	Rect(float,float);

	float Perimeter();
	float Area();
	float Area(Rect);
};

