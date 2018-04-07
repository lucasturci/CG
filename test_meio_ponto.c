#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

void draw_eight(int x, int y, ALLEGRO_COLOR col) {
	al_draw_pixel(x + DISPLAY_WIDTH/2, y + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(x + DISPLAY_WIDTH/2, -y + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(-x + DISPLAY_WIDTH/2, y + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(-x + DISPLAY_WIDTH/2, -y + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(y + DISPLAY_WIDTH/2, -x + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(-y + DISPLAY_WIDTH/2, x + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(y + DISPLAY_WIDTH/2, x + DISPLAY_HEIGHT/2, col);
	al_draw_pixel(-y + DISPLAY_WIDTH/2, -x + DISPLAY_HEIGHT/2, col);
}

void draw_circle(int r, ALLEGRO_COLOR col) {
	int x, y, d;

	x = 0;
	y = r;

	d = 1 - r;

	draw_eight(0, r, col);
	for(x = 0, y = r; y > x; x++) {

		//Escolhe E
		if(d < 0) d += 2 * x + 3;
		else {
			d += 2 * (x - y) + 5;
			y--;
		}

		draw_eight(x, y, col);
	}
}

int main() {
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY * display;

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);

	for(int r = 25; r <= 250; r += 25) {
		clock_t t = clock();
		for(int i = 0; i < 100; ++i) {
			draw_circle(r, white);
		}

		double tim = (clock() - t)/(1.0 * CLOCKS_PER_SEC);
		printf("R = %d Tempo medio = %lf\n", r, tim/100); 
		al_flip_display(); //atualiza o canvas
	}

	return 0;
}