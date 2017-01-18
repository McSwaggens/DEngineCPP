#include "font.h"
#include "font_internal.h"
#include "logger.h"

#ifdef __linux__
	#define TTF_FONT_PATH "/usr/share/fonts/TTF/"
#elif __APPLE__ && TARGET_OS_MAC
	#define TTF_FONT_PATH "/Library/Fonts/"
#elif
	#error Operating system not supported.
#endif

std::vector<TTF_Font*> FontInternal::fonts;

TTF_Font* FontInternal::GetSDLFont (FONT font)
{
	return FontInternal::fonts[font];
}

FONT Font::CreateFont (std::string font_name, uint32_t font_size)
{
	std::string path = TTF_FONT_PATH + font_name + ".ttf";
	
	TTF_Font* new_font = TTF_OpenFont (path.c_str(), font_size);
	
	
	if (!new_font)
	{
		// TODO: Throw error
		
		printf("[ERROR]: Font not found: %s\n", font_name.c_str());
		
		return 0;
	}
	
	FONT index = FontInternal::fonts.size(); 
	FontInternal::fonts.push_back (new_font);
	 
	return index;
}

bool FontInternal::Initialize_SDL_TTF()
{
	Log ("Initializing Font System");
	
	Log ("Initializing SDL TTF (TTF_Init)");
	if (TTF_Init () != 0)
	{
		Log ("TTF_Init Error: ", SDL_GetError());
		return false;
	}
	
	return true;
}

void FontInternal::Shutdown_SDL_TTF ()
{
	TTF_Quit ();
}
