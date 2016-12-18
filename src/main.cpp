#include <iostream>
#include <stdio.h>
#include "engine.h"
#include "entity.h"
#include "render.h"
#include <math.h>

#define PI 3.14159265

class Sinner : public Entity, public Actor
{
	float i = 0;
	float s = 0;
	
	virtual void Tick ()
	{
		i += 2 * Time::delta;
	}
	
	virtual void Render ()
	{
		Vector pos (-1, 400);
		Vector last (0, 0);
		
		float dd = 0.0f;
		float ddd = 0.0f;
		for (float d = 0.0f, pixel = 0; pixel < 1920; pixel += 5, d += 0.05f, dd += 0.65f, ddd += 0.8f)
		{
			//s = (sin (d+i) * PI * 20) / cos (sin (d));
			s = (sin (d+i) * PI * 20) + (sin (dd+i) * PI * 2) + (sin (ddd+(i + 0.5f)) * PI + 1.2f);
			
			Vector next (pixel, s);
			
			Render::DrawLine (pos + last, pos + next, Color (255, 255, 255, 255));
			
			last = next;
		}
	}
};

int main ()
{
	Engine::Initialize ();
	Engine::SetSize (Vector(1920, 1080));
	
	Sinner sinner;
	Engine::RegisterEntity (&sinner);
	Engine::RegisterActor (&sinner);
	
	Engine::Start ();
	
	return 0;
}