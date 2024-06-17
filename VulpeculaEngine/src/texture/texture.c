#include "texture.h"

#include "../common/common.h"
#include "../memory/memory.h"
#include "texture_defs.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

SLoadedTexturesPool *init_loaded_textures_pool() {
  SLoadedTexturesPool *t =
      alloc_struct(SLoadedTexturesPool, ENGINE_MALLOC_AUTO);
  t->lastId = 0;
  t->textures = array_create(32, sizeof(STexture));
  return t;
}

void free_loaded_textures_pool(SLoadedTexturesPool *pool) {}

STexture *load_texture(char *file, const char *name, SEngineApp *engineApp) {
  STexture *tex = alloc_struct(STexture, ENGINE_MALLOC_AUTO);
  tex->id = (++(engineApp->loadedTextures->lastId));
  tex->sdlTexture = IMG_LoadTexture(engineApp->renderer, file);
  memset(tex->name, 0, TEX_MAX_NAME_LEN);
  strncat(tex->name, name, TEX_MAX_NAME_LEN);
  tex->name[31] = '\0';
  if (tex->sdlTexture == NULL) {
    printf("Failed to load image! %s\n", IMG_GetError());
    return NULL;
  }
  array_push_back(tex, engineApp->loadedTextures->textures);
  return tex;
}

STexture *get_texture(uint32_t id, SEngineApp *engineApp) {
  if (id == 0 || id > engineApp->loadedTextures->textures->size)
    return NULL;
  return array_get_at(engineApp->loadedTextures->textures, STexture, id - 1);
}

STexture *get_texture_by_name(const char *name, SEngineApp *engineApp) {
  if (engineApp->loadedTextures->textures->size == 0)
    return NULL;
  STexture *t = NULL;
  for (size_t i = 0; i < engineApp->loadedTextures->textures->size; i++) {
    t = array_get_at(engineApp->loadedTextures->textures, STexture, i);
	printf("%s vs %s\n", t->name, name);
    if (strcmp(name, t->name) == 0) {
      return t;
    }
  }
  return NULL;
}