#include "logger.h"

using namespace std;

// CHAR
void Log (string message)
{
	cout << message << endl;
}
void Log (string name, const char* data)
{
	cout << name << ": " << data << endl;
}

//COLOR
void Log (Color color)
{
	cout << "r: " << color.r << " g: " << color.g << " b: " << color.b << " a: " << color.a << endl;
}
void Log (string name, Color color)
{
	cout << name << ": r: " << color.r << " g: " << color.g << " b: " << color.b << " a: " << color.a << endl;
}

// VECTOR
void Log (Vector vector)
{
	cout << "x: " << vector.x << " y: " << vector.y << endl;
}
void Log (string name, Vector vector)
{
	cout << name << ": x: " << vector.x << " y: " << vector.y << endl;
}