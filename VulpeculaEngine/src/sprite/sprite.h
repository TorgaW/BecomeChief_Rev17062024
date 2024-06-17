#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL_render.h>

typedef struct SSprite {
	int x, y;
	SDL_Texture* texture;
} SSprite;

#endif /* SPRITE */
