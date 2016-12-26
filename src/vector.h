#pragma once

#define LOC Vector2D
#define SIZE Vector2D

#define VP(c) c.x, c.y
#define VPI(c) (int)c.x, (int)c.y
#define Vector Vector2D
#define IVector IVector2D

struct Vector2D;
struct IVector2D;

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
	
	Vector2D (int x, int y)
	{
		this->x = (float)x;
		this->y = (float)y;
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
	
	IVector2D ToIVector ();
};


// Mainly used for internal engine methods like screen reslution etc..
struct IVector2D
{
	int x;
	int y;
	
	IVector2D ()
	{
		this->x = 0;
		this->y = 0;
	}
	
	
	IVector2D (int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	IVector2D (float x, float y)
	{
		this->x = (int)x;
		this->y = (int)y;
	}
	
	IVector2D (Vector2D vector)
	{
		*this = vector;
	}
	
	IVector2D operator + (const IVector2D &v) const
	{
		return IVector (x + v.x, y + v.y);
	}
	
	IVector2D operator - (const IVector2D &v) const
	{
		return IVector (x - v.x, y - v.y);
	}
	
	IVector2D operator * (const IVector2D &v) const
	{
		return IVector (x * v.x, y * v.y);
	}
	
	IVector2D operator / (const IVector2D &v) const
	{
		return IVector (x / v.x, y / v.y);
	}
	
	Vector2D ToVector ();
};
