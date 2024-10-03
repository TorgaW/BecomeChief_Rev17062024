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

#define TEX_MAX_NAME_LEN 32

typedef struct STexture 
{	
	uint32_t id;
	SDL_Texture* sdlTexture;
	char name[TEX_MAX_NAME_LEN+1];
} STexture;

#endif /* TEXTURE_DEFS */
