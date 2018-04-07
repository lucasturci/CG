#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

int main() {
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY * display;

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	while(1) {
		
	}

	return 0;
}