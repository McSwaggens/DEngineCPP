#include "render.h"
#include "engine_internal.h"
#include "SDL/SDL_opengl.h"
#include "font_internal.h"

#define render EngineInternal::render

void Render::Clear ()
{
	SDL_SetRenderDrawColor (render, 0x00, 0x00, 0x00, 0xFF);
	
	SDL_RenderClear (render);
}

void Render::Clear (Color color)
{
	SDL_SetRenderDrawColor (render, color.r, color.g, color.b, color.a);
	
	SDL_RenderClear (render);
}

void Render::DrawLine (Vector2D start, Vector2D end, Color color)
{
	SDL_SetRenderDrawColor (render, CP(color));
	
	SDL_RenderDrawLine (render, VPI (start), VPI (end));
}

void Render::DrawFilledRectangle (Vector2D start, Vector2D size, Color color)
{
	SDL_SetRenderDrawColor (render, CP(color));
	
	SDL_Rect rect = { VPI(start), VPI(size) };
	
	SDL_RenderFillRect (render, &rect);
}

void Render::DrawRectangle (Vector2D start, Vector2D size, Color color)
{
	SDL_SetRenderDrawColor (render, CP(color));
	
	SDL_Rect rect = { VPI(start), VPI(size) };
	
	SDL_RenderDrawRect (render, &rect);
}

void Render::DrawString(Vector2D position, std::string text, FONT font, Color color)
{
	SDL_Color text_color = { CP(color) };
	
	TTF_Font* fnt = FontInternal::GetSDLFont(font);
	
	SDL_Surface* surface = TTF_RenderText_Solid (FontInternal::GetSDLFont(font), text.c_str(), text_color);
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
	
	size_t width = surface->w;
	size_t height = surface->h;
	
	SDL_FreeSurface (surface);
	
	SDL_Rect rect = { position.x, position.y, width, height };
	
	SDL_RenderCopy (render, texture, NULL, &rect);
	
	SDL_DestroyTexture (texture);
}

void Render::PushRender ()
{
	SDL_RenderPresent (render);
}
