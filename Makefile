NAME=sharte
CC=clang
CFLAGS=-g -Wall -Wextra -std=c11 -pedantic -fsanitize=undefined -fsanitize=address
SRC=src/main.c

all: clean build

build: $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@rm -f $(NAME)
