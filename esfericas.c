#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define DISPLAY_WIDTH 540
#define DISPLAY_HEIGHT 540

float pi;

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


/* Desenha um circulo atraves do metodo das coordenadas esfericas */
void draw_circle(int r, ALLEGRO_COLOR col) {
	float theta = 0.0;

	for(theta = 0.0; theta < pi/2.0; theta += 0.02) {
		int x = round(r * cos(theta));
		int y = round(r * sin(theta));
		draw_eight(x, y, col);
	}
}

int main() {
	// Inicializacao das bibliotecas
	al_init();
	al_init_primitives_addon();

	int r;
	pi = acos(-1); // PI

	ALLEGRO_DISPLAY * display; 

	printf("Qual é o raio do seu círculo?\n");
	scanf("%d", &r);

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT); //Cria o display

	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255); 
	
	draw_circle(r, white); //Desenha o circulo

	al_flip_display(); //atualiza o canvas

	printf("Digite qualquer coisa para sair\n");

	scanf("%*s");

	return 0;
}