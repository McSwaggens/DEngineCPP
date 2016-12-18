#include "time.h"

// TIME DATA
uint64_t Time::last = 0;
uint64_t Time::now = 0;
double Time::delta = 0.0d;

void Time::CalculateTime ()
{
	Time::last = Time::now;
	Time::now = SDL_GetTicks ();
	
	Time::delta = (double)(Time::now - Time::last) / 1000.0d;
}