#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include "entity.h"
#include "actor.h"
#include "physical.h"
#include "vector.h"
#include "engine_types.h"
#include "time.h"

using namespace Time;

#define FLAG = 1 <<

enum CLASS
{
	ENTITY		FLAG 0,
	ACTOR		FLAG 1,
	PHYSICAL	FLAG 2,
};


#undef FLAG

namespace Engine
{
	extern std::string game_name;

	extern std::vector<Entity*> entities;
	extern std::vector<Actor*> actors;
	extern std::vector<Physical*> physicals;
	extern std::vector<Entity*> event_listener_entities;

// MEMBER FUNCTIONS
	void Initialize ();
	void Start ();
	void Shutdown ();


	void RegisterEntity (Entity* entity);
	void RegisterActor (Actor* actor);
	void RegisterPhysical (Physical* physical);

	void SetTitle (std::string title);
	void SetSize (Vector size);
}
