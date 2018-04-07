#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

/* Desenha um circulo atraves do metodo tradicional - equacao da circunferencia */
void draw_circle(int r, ALLEGRO_COLOR col) {

	for(int x = -r; x <= r; ++x) {
		int y = round(sqrt(((float)r) * r - ((float)x) * x));
		al_draw_pixel(x + DISPLAY_WIDTH/2, y + DISPLAY_HEIGHT/2, col);	
		al_draw_pixel(x + DISPLAY_WIDTH/2, -y + DISPLAY_HEIGHT/2, col);
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
	
	draw_circle(r, white); //Desenha o circulo

	al_flip_display(); //atualiza o canvas

	printf("Digite qualquer coisa para sair\n");

	scanf("%*s");

	return 0;
}