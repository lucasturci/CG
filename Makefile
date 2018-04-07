SRC = $(wildcard *.c)
OBJECTS = $(SRC:.c=.o)
LINKS = -lallegro_main -lallegro_primitives -lallegro

meio_ponto: $(OBJECTS)
	@gcc -o $@ meio_ponto.o $(LINKS) -L./lib -I./include
naive: $(OBJECTS)
	@gcc -o $@ naive.o $(LINKS) -L./lib -I./include
trigo: $(OBJECTS)
	@gcc -o $@ trigo.o $(LINKS) -L./lib -I./include
run:
	@./$(f)	
%.o: %.c
	@gcc -o $@ -c $< -I./