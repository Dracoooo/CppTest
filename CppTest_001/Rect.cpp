#include "stdafx.h"
#include "Rect.h"


Rect::Rect()
{
	this->length = 0;
	this->width = 0;
}

Rect::Rect(float length, float width) {
	if (length > 0) {
		this->length = length;
	}
	else {
		this->length = 0;
	}
	if (width > 0) {
		this->width = width;
	}
	else {
		this->width = 0;
	}
}

float Rect::Perimeter() {
	return length * 2 + width * 2;
}

float  Rect::Area() {
	return length*width;
}

float  Rect::Area(Rect other) {
	return length*width + other.Area();
}