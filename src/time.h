#pragma once

#include <stdint.h>
#include <stddef.h>
#include <SDL.h>

namespace Time
{
	extern uint64_t last;
	extern uint64_t now;
	extern double delta;
	
	void CalculateTime ();
}