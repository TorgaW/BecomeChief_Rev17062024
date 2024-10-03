#ifndef KEYBOARD
#define KEYBOARD

#include <SDL2/SDL.h>

typedef struct SKeyboard
{
	unsigned char keys[SDL_NUM_SCANCODES];
} SKeyboard;

#endif /* KEYBOARD */
