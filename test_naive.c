#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

float pi;

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
	float theta = 0.0;

	for(theta = 0.0; theta < pi/2.0; theta += 10/(2 * pi * r)) {
		int x = round(r * cos(theta));
		int y = round(r * sin(theta));
		draw_eight(x, y, col);
	}
}

int main() {
	al_init();
	al_init_primitives_addon();

	int r;
	pi = acos(-1);

	ALLEGRO_DISPLAY * display;

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	//al_draw_pixel(50, 50, white);

	for(int r = 250; r >= 25; r -= 25) {
		clock_t t = clock();
		for(int i = 0; i < 100; ++i) {
			draw_circle(r, white);
		}

		double tim = (clock() - t)/(1.0 * CLOCKS_PER_SEC);
		printf("R = %d Tempo medio = %lf\n", r, tim/100.0); 
		al_flip_display(); //atualiza o canvas
	}

	al_flip_display(); //atualiza o canvas

	return 0;
}