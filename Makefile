CC = gcc
CFLAGS = -Wall -I include # -Werror -Wextra -Wpedantic -g -I include
OBJ = BankSystem
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c,%.o,$(SOURCES))

%.o: src/%.c 
	$(CC) -c $(CFLAGS) $^

$(OBJ): $(OBJECTS)
	$(CC) $(CFLAGS) apps/main.c $? -o $@

all: $(OBJ)

exec: all
	./$(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.o 
	rm -f records.*

.PHONY: clean