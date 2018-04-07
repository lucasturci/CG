SRC = $(wildcard *.c)
OBJECTS = $(SRC:.c=.o)
LINKS = -lallegro_main -lallegro_primitives -lallegro

meio_ponto: $(OBJECTS)
	@gcc -o $@ meio_ponto.o $(LINKS)
naive: $(OBJECTS)
	@gcc -o $@ naive.o $(LINKS)
trigo: $(OBJECTS)
	@gcc -o $@ trigo.o $(LINKS)
run:
	@./$(f)	
%.o: %.c
	@gcc -o $@ -c $<