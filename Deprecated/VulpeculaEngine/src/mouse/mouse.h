#ifndef MOUSE
#define MOUSE

typedef struct SMouse {
	char wheel;
	unsigned char buttons[2];
	int x, y;
} SMouse;

#endif /* MOUSE */
