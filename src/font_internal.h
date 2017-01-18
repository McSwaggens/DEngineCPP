#include <SDL2/SDL_ttf.h>
#include <vector>
#include "font.h"

namespace FontInternal
{
	extern std::vector<TTF_Font*> fonts;
	TTF_Font* GetSDLFont (FONT font);
	bool Initialize_SDL_TTF ();
	void Shutdown_SDL_TTF ();
}
