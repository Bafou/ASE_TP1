CC = gcc

all:display_stack try_mul

try_mul:try_mul.c
	$(CC) -o try_mul try.c try_mul.c

clean:
	rm -f *~ *.o *#
	rm display_stack
	rm try_mul

stack:display_stack
	./display_stack

trymul:try_mul
	./try_mul
