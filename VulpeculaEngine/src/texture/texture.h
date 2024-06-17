#ifndef TEXTURE
#define TEXTURE

#include "../engine/engine_defs.h"

SLoadedTexturesPool* init_loaded_textures_pool();
void free_loaded_textures_pool(SLoadedTexturesPool* pool);

STexture* load_texture(char* file, SEngineApp* engineApp);

#endif /* TEXTURE */
