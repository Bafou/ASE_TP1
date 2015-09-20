CC = gcc

all:display_stack try_mul

try.o:try.c
	$(CC) -c try.c

display_stack:display_stack.c
	$(CC) -o display_stack display_stack.c

try_mul:try_mul.c try.o
	$(CC) -o try_mul try.c try_mul.c

clean:
	rm -f *~ *.o *#
	rm display_stack
	rm try_mul

displaystack:display_stack
	./display_stack

trymul:try_mul
	./try_mul
