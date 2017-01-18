#pragma once

#include <SDL.h>
#include "color.h"
#include "vector.h"
#include <string>
#include "font.h"

namespace Render
{
	void Clear ();
	void Clear (Color color);
	
	void DrawLine (Vector2D start, Vector2D end, Color color);
	void DrawFilledRectangle (Vector2D start, Vector2D size, Color color);
	void DrawRectangle (Vector2D start, Vector2D size, Color color);
	void DrawString (Vector2D position, std::string text, FONT font, Color color);
	
	void PushRender ();
}
