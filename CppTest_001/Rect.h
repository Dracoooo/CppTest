#pragma once
class Rect
{
public:
	//TODO:�Ƿ���ù�ͬ���ʡ�ڴ�ռ�
	float length;
	float width;
	Rect();
	Rect(float,float);

	float Perimeter();
	float Area();
	float Area(Rect);
};

