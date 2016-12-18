#pragma once

#define CP(c) c.r, c.g, c.b, c.a

struct Color
{
	int r, g, b, a;
	
	Color (int r, int g, int b, int a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	
	Color (int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 255;
	}
};