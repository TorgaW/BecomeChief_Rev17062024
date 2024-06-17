#ifndef TEXTURE
#define TEXTURE

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "../engine/engine.h"

SDL_Texture* load_texture(char* file, SEngineApp* engineApp);

#endif /* TEXTURE */
