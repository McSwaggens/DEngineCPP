#include "logger.h"

using namespace std;

// INT
void Log (uint64_t number)
{
	cout << number << endl;
}
void Log (string name, uint64_t number)
{
	cout << name << ": " << number << endl;
}

void Log (uint32_t number)
{
	cout << number << endl;
}
void Log (string name, uint32_t number)
{
	cout << name << ": " << number << endl;
}

void Log (int number)
{
	cout << number << endl;
}
void Log (string name, int number)
{
	cout << name << ": " << number << endl;
}

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

// IVECTOR
void Log (IVector vector)
{
	cout << "x: " << vector.x << " y: " << vector.y << endl;
}
void Log (string name, IVector vector)
{
	cout << name << ": x: " << vector.x << " y: " << vector.y << endl;
}
