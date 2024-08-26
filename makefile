CC=gcc
CFLAGS=-Wextra -Wall -g -Iheaders
SRC= $(wildcard src/*.c)
OBJ= $(SRC:src/%.c=obj/%.o)

prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

obj/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: 
	clean mrproper

clean:
	rm -rf obj/*.o