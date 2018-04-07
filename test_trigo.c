#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

ALLEGRO_COLOR white;
void draw_circle(int r) {

	for(int x = -r; x <= r; ++x) {
		int y = round(sqrt(((float)r) * r - ((float)x) * x));
		al_draw_pixel(x + DISPLAY_WIDTH/2, y + DISPLAY_HEIGHT/2, white);	
		al_draw_pixel(x + DISPLAY_WIDTH/2, -y + DISPLAY_HEIGHT/2, white);
	}
}

int main() {
	al_init();
	al_init_primitives_addon();

	int r;

	ALLEGRO_DISPLAY * display;

	printf("Qual é o raio do seu círculo?\n");
	scanf("%d", &r);

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	white = al_map_rgb(255, 255, 255);

	for(int r = 25; r <= 250; r += 25) {
		clock_t t = clock();
		for(int i = 0; i < 100; ++i) {
			draw_circle(r);
		}

		double tim = (clock() - t)/(1.0 * CLOCKS_PER_SEC);
		printf("R = %d Tempo medio = %lf\n", r, tim/100); 
		al_flip_display(); //atualiza o canvas
	}
	
	al_flip_display(); //atualiza o canvas

	printf("Digite qualquer coisa para sair\n");

	scanf("%*s");

	return 0;
}