#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL_render.h>
#include "../texture/texture_defs.h"

typedef struct SSprite {
	int x, y;
	STexture* texture;
} SSprite;

#endif /* SPRITE */
