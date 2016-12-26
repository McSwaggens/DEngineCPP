#include "engine.h"
#include "engine_internal.h"
#include "logger.h"
#include "render.h"

using namespace EngineInternal;

//.CPP
bool sdl_initialized = false;

// ENGINE
SDL_Window*		EngineInternal::window;
SDL_Renderer*	EngineInternal::render;

std::string Engine::game_name = "dengine";
Vector EngineInternal::screen_resolution = Vector (1280, 720);

// WORLD
std::vector<Entity*>	Engine::entities;
std::vector<Actor*>		Engine::actors;
std::vector<Physical*>	Engine::physicals;
std::vector<Entity*>	Engine::event_listener_entities;

bool EngineInternal::running = false;

bool EngineInternal::Initialize_SDL ()
{
	Log ("Initializing SDL..");
	
	Log ("Initializing SDL (SDL_INIT)");
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		Log ("SDL_Init Error: ", SDL_GetError());
		return false;
	}
	
	
	Log ("Initializing SDL window");
	EngineInternal::window = SDL_CreateWindow (Engine::game_name.c_str(), 100, 100, (int)screen_resolution.x, (int)screen_resolution.y, SDL_WINDOW_SHOWN);
	
	if (EngineInternal::window == nullptr)
	{
		Log ("SDL_CreateWindow Error: ", SDL_GetError());
		SDL_Quit();
		return false;
	}
	
	Log ("Initializing SDL Renderer");
	EngineInternal::render = SDL_CreateRenderer(EngineInternal::window, -1, SDL_RENDERER_ACCELERATED);
	if (EngineInternal::render == nullptr)
	{
		SDL_DestroyWindow(EngineInternal::window);
		Log ("SDL_CreateRenderer Error: ", SDL_GetError());
		SDL_Quit();
		return false;
	}
	
	Log ("SDL initialization finished.");
	
	return true;
}

void EngineInternal::ProcessEngineEvent (SDL_Event event)
{
	if (event.type == SDL_QUIT)
	{
		Engine::Shutdown ();
	}
}

void EngineInternal::HandleEvents ()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event) != 0)
	{
		// Send the event to the engine to be processed
		ProcessEngineEvent (event);
		
		// Send the event to all listening entities
		for (uint64_t i = 0; i < Engine::event_listener_entities.size(); i++)
		{
			Entity* entity = Engine::event_listener_entities[i];
			
			entity->OnEventCalled (event);
		}
	}
}

void EngineInternal::CalculateEntities ()
{
	// Loop through all entities
	for (uint64_t i = 0; i < Engine::entities.size(); i++)
	{
		// Grab the entity pointer
		Entity* entity = Engine::entities[i];
		
		// Call the entity tick code
		entity->Tick ();
	}
}

void EngineInternal::RenderActors ()
{
	// Loop through all actors
	for (uint64_t i = 0; i < Engine::actors.size(); i++)
	{
		// Grab the actor pointer
		Actor* actor = Engine::actors[i];
		
		// Call the entity tick code
		actor->Render ();
	}
}

// Called before all actors are rendered onto the screen
void EngineInternal::PreRender ()
{
	// Clear the screen (black)
	Render::Clear ();
}

// Called after everything has been calculated and rendered onto the screen
void EngineInternal::PostRender ()
{
	Render::PushRender ();
}

// Main engine loop
void EngineInternal::TickLoop ()
{
	// Infinite loop until "running" variable is false
	while (running)
	{
		// Update the time information
		CalculateTime ();
		
		// Handle all the events since the last tick
		HandleEvents ();
		
		// Call the prerender method (clear the screen)
		PreRender ();
		
		// Loop through all entities and call their tick method
		CalculateEntities ();
		
		// Render all the actors to the screen
		RenderActors ();
		
		// Call the engine post render code
		PostRender ();
	}
}

void Engine::Initialize ()
{
	if (Initialize_SDL ())
	{
		sdl_initialized = true;
		
		//...//
	}
}

void Engine::Start ()
{
	running = true;
	
	TickLoop ();
}

void Engine::Shutdown ()
{
	printf ("Shutting down engine...\n");
	running = false;
	SDL_DestroyWindow (EngineInternal::window);
	SDL_Quit ();
}

const Vector Engine::GetScreenSize ()
{
	return screen_resolution;
}

const std::string Engine::GetTitle ()
{
	return game_name;
}

void Engine::SetTitle (std::string title)
{
	SDL_SetWindowTitle (EngineInternal::window, title.c_str());
}

void Engine::SetSize (Vector2D size)
{
	SDL_SetWindowSize (window, size.x, size.y);
}

void Engine::RegisterEntity (Entity* entity)
{
	Engine::entities.push_back (entity);
}

void Engine::RegisterActor (Actor* actor)
{
	Engine::actors.push_back (actor);
}

void Engine::RegisterPhysical (Physical* physical)
{
	Engine::physicals.push_back (physical);
}
