#pragma once

#include <stdint.h>
#include "vector.h"
#include "logger.h"

namespace EngineInternal
{
	extern bool running;
	extern Vector screen_resolution;
//SDL	
	extern SDL_Window* window;
	extern SDL_Renderer* render;

// METHODS
	bool Initialize_SDL ();
	void ProcessEngineEvent (SDL_Event event);
	void HandleEvents ();
	void CalculateEntities ();
	void RenderActors ();
	void PreRender ();
	void PostRender ();
	void TickLoop ();
}
