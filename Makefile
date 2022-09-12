

CC=gcc
CFLAGS=-g -Wall -Wextra -Werror

main.o: main.c
	$(CC) $(CFLAGS) -c $^

fibnim.o: fibnim.h fibnim.c myassert.h
	$(CC) $(CFLAGS) -c $^

matrix.o: matrix.h matrix.c
	$(CC) $(CFLAGS) -c $^

myapp: main.o matrix.o fibnim.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm myapp *.o *.gch