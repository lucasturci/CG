SRC = $(wildcard *.c)
LINKS = -lallegro_main -lallegro_primitives -lallegro

meio_ponto: meio_ponto.o
	@gcc -o $@ $@.o $(LINKS)
naive: naive.o
	@gcc -o $@ $@.o $(LINKS) -lm
trigo: trigo.o
	@gcc -o $@ $@.o $(LINKS) -lm
test_meio_ponto: test_meio_ponto.o
	gcc -o $@ $@.o $(LINKS) -lm
test_trigo: test_trigo.o
	gcc -o $@ $@.o $(LINKS) -lm
test_naive: test_naive.o
	gcc -o $@ $@.o $(LINKS) -lm
run:
	@./$(f)	
%.o: %.c
	gcc -o $@ -c $<

clean:
	rm *.o test_trigo test_naive test_meio_ponto naive meio_ponto