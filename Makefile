SRC = $(wildcard *.c)
LINKS = -lallegro_main -lallegro_primitives -lallegro

ponto_medio: ponto_medio.o
	@gcc -o $@ $@.o $(LINKS)
esfericas: esfericas.o
	@gcc -o $@ $@.o $(LINKS) -lm
tradicional: tradicional.o
	@gcc -o $@ $@.o $(LINKS) -lm
run:
	@./$(f)	
%.o: %.c
	@gcc -o $@ -c $<

clean:
	rm *.o tradicional esfericas ponto_medio