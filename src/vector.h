#pragma once

#define LOC Vector2D
#define SIZE Vector2D

#define VP(c) c.x, c.y
#define Vector Vector2D

struct Vector2D
{
	int x;
	int y;
	
	Vector2D (int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	Vector2D operator + (const Vector2D &v) const
	{
		return Vector (x + v.x, y + v.y);
	}
	
	Vector2D operator - (const Vector2D &v) const
	{
		return Vector (x - v.x, y - v.y);
	}
	
	Vector2D operator * (const Vector2D &v) const
	{
		return Vector (x * v.x, y * v.y);
	}
	
	Vector2D operator / (const Vector2D &v) const
	{
		return Vector (x / v.x, y / v.y);
	}
};