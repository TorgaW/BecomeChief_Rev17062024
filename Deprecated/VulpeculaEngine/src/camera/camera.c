#include "camera.h"
#include "../math/fmath.h"

void camera_movement(SEngineApp *engineApp) {
  if (engineApp->keyboard->keys[SDL_SCANCODE_W] == 1) {
    engineApp->camera->y -= CAMERA_SPEED / engineApp->camera->zoom * engineApp->framesDelta;
  }
  if (engineApp->keyboard->keys[SDL_SCANCODE_S] == 1) {
    engineApp->camera->y += CAMERA_SPEED / engineApp->camera->zoom * engineApp->framesDelta;
  }
  if (engineApp->keyboard->keys[SDL_SCANCODE_A] == 1) {
    engineApp->camera->x -= CAMERA_SPEED / engineApp->camera->zoom * engineApp->framesDelta;
  }
  if (engineApp->keyboard->keys[SDL_SCANCODE_D] == 1) {
    engineApp->camera->x += CAMERA_SPEED / engineApp->camera->zoom * engineApp->framesDelta;
  }
  if (engineApp->mouse->wheel < 0) {
    engineApp->camera->zoom = fm_clamp(engineApp->camera->zoom - 0.05, 0.25, 3.0);
  } else if (engineApp->mouse->wheel > 0) {
    engineApp->camera->zoom = fm_clamp(engineApp->camera->zoom + 0.05, 0.25, 3.0);
  }
}
