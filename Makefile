CC ?= cc
CFLAGS ?= -Wall -Wextra -std=c99 -I.

OBJ = $(SRC:.c=.o)

all: example

example: example.c
	$(CC) $(CFLAGS) -o zline-example example.c

clean:
	rm -f $(OBJ) zline-example
