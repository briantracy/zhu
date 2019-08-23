# zhu -- makefile

CC = gcc-8
CFLAGS = --std=c99 -Wall -Wextra -Wpedantic -Ofast -fsanitize=address -pthread
LDFLAGS = -fsanitize=address
SRC = src/*.c
EXECS = engine test

.PHONY: all clean

all: engine test

engine: $(SRC) main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

test: $(SRC) test.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)	

clean:
	rm -f $(EXECS)
