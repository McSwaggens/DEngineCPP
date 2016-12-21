#pragma once

#define LOC Vector2D
#define SIZE Vector2D

#define VP(c) c.x, c.y
#define VPI(c) (int)c.x, (int)c.y
#define Vector Vector2D

struct Vector2D
{
	float x;
	float y;
	
	Vector2D ()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	
	Vector2D (float x, float y)
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