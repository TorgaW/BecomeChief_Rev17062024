#ifndef TEXTURE
#define TEXTURE

#include "../engine/engine_defs.h"
#include <stdint.h>

SLoadedTexturesPool* init_loaded_textures_pool();
void free_loaded_textures_pool(SLoadedTexturesPool* pool);

STexture* load_texture(char* file, const char* name, SEngineApp* engineApp);

STexture* get_texture(uint32_t id, SEngineApp* engineApp);
STexture* get_texture_by_name(const char* name, SEngineApp* engineApp);

#endif /* TEXTURE */
