#pragma once

#include <stdint.h>
#include <string>

typedef uint16_t FONT;

namespace Font
{
	FONT CreateFont (std::string font_name, uint32_t font_size);
}
