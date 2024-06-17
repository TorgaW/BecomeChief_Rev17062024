#ifndef TEXTURE_DEFS
#define TEXTURE_DEFS

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <stdint.h>

#include "../darray/darray.h"

typedef struct SLoadedTexturesPool
{
	uint32_t lastId;
	SArray* textures;
} SLoadedTexturesPool;

typedef struct STexture 
{	
	uint32_t id;
	SDL_Texture* sdlTexture;
} STexture;

#endif /* TEXTURE_DEFS */
