# zhu -- makefile

CC = gcc-8
CFLAGS = --std=c99 -Wall -Wextra -Wpedantic -Ofast
SRC = src/*.c
EXECS = engine test

.PHONY: all clean

all: engine test

engine: $(SRC) main.c
	$(CC) $(CFLAGS) $^ -o $@

test: $(SRC) test.c
	$(CC) $(CFLAGS) $^ -o $@	

clean:
	rm -f $(EXECS)
