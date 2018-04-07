SRC = $(wildcard *.c)
OBJECTS = $(SRC:.c=.o)
LINKS = -lallegro_main -lallegro_primitives -lallegro

meio_ponto: $(OBJECTS)
	@gcc -o $@ meio_ponto.o $(LINKS)
naive: $(OBJECTS)
	@gcc -o $@ naive.o $(LINKS) -lm
trigo: $(OBJECTS)
	@gcc -o $@ trigo.o $(LINKS) -lm
test_meio_ponto: $(OBJECTS)
	@gcc -o $@ $@.o $(LINKS) -lm
test_trigo: $(OBJECTS)
	@gcc -o $@ $@.o $(LINKS) -lm
test_naive: $(OBJECTS)
	@gcc -o $@ $@.o $(LINKS) -lm
run:
	@./$(f)	
%.o: %.c
	@gcc -o $@ -c $<

clean:
	rm *.o test_trigo test_naive test_meio_ponto naive meio_ponto