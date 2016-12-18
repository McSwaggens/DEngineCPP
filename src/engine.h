#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include "entity.h"
#include "actor.h"
#include "vector.h"
#include "engine_types.h"
#include "time.h"

using namespace Time;

extern uint64_t last;
extern uint64_t now;
extern double delta;

namespace Engine
{
	extern std::string game_name;

	extern std::vector<Entity*> entities;
	extern std::vector<Actor*> actors;
	extern std::vector<Entity*> event_listener_entities;

// MEMBER FUNCTIONS	
	void Initialize ();
	void Start ();
	void Shutdown ();
	
	void RegisterEntity (Entity* entity);
	void RegisterActor (Actor* actor);
	
	void SetTitle (std::string title);
	void SetSize (Vector size);
}
