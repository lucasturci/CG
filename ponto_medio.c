#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

/* Desenha o pixel nos oito octantes do plano */
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

/* Desenha um circulo atraves do algoritmo do ponto medio */
void draw_circle(int r, ALLEGRO_COLOR col) {
	int x, y, d;

	d = 1 - r;

	draw_eight(0, r, col); //Desenha o primeiro ponto
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
	// Inicializacao das bibliotecas
	al_init();
	al_init_primitives_addon();

	int r;

	ALLEGRO_DISPLAY * display;

	printf("Qual é o raio do seu círculo?\n");
	scanf("%d", &r);

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	draw_circle(r, white); //Desenha o circulo de raio r e cor branca
	

	al_flip_display(); //atualiza o canvas

	printf("Digite qualquer coisa para sair\n");

	scanf("%*s");

	return 0;
}