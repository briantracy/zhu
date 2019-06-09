# zhu -- makefile

CC = gcc-8
CFLAGS = -Wall -std=gnu99
SRC = engine.c
EXECS = engine

.PHONY: all clean

all: $(EXECS)

engine: engine.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(EXECS)
