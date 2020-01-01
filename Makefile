CC=gcc
CFLAGS=-std=c99 -Wall

all: benchmark

benchmark: benchmark.c
	$(CC) $(CFLAGS) $^ -o $@
   
clean:
	rm -f benchmark
