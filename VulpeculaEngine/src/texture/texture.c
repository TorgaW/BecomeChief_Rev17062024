#include "texture.h"

SDL_Texture* load_texture(char* file, SEngineApp* engineApp)
{
	SDL_Texture* tex;
	tex = IMG_LoadTexture(engineApp->renderer, file);
	return tex;
}