#include "texture.h"

#include "../memory/memory.h"
#include "../common/common.h"
#include "texture_defs.h"
#include <stdio.h>

SLoadedTexturesPool* init_loaded_textures_pool()
{
	SLoadedTexturesPool *t = alloc_struct(SLoadedTexturesPool, ENGINE_MALLOC_AUTO);
	t->lastId = 0;
	t->textures = array_create(32, sizeof(STexture));
	return t;
}

void free_loaded_textures_pool(SLoadedTexturesPool* pool)
{

}

STexture* load_texture(char* file, SEngineApp* engineApp)
{
	STexture *tex = alloc_struct(STexture, ENGINE_MALLOC_AUTO);
	tex->id = (++(engineApp->loadedTextures->lastId));
	tex->sdlTexture = IMG_LoadTexture(engineApp->renderer, file);
	if(tex->sdlTexture == NULL)
	{
		printf("Failed to load image! %s\n", IMG_GetError());
	}
	array_push_back(tex, engineApp->loadedTextures->textures);
	return tex;
}