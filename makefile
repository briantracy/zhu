# zhu -- makefile

CC = gcc-8
CFLAGS = -Wall -std=gnu99 -Ofast
SRC = engine.c complex.c
EXECS = engine

.PHONY: all clean

all: $(EXECS)

engine: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(EXECS)
