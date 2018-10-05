.PHONY: all cls compile run clean test

CC=gcc
CFLAGS=-std=c99
EXECUTABLE=project
SOURCES=main.c array_functions.c unit.c
OBJECTS=$(SOURCES:.c=.o)

all: cls compile run clean

cls:
	clear

compile: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(EXECUTABLE)

test:
	./$(EXECUTABLE) --test

main.o: main.c
	$(CC) -c $^ -o $@

array_functions.o: array_functions.c
	$(CC) -c $^ -o $@

unit.o: unit.c
	$(CC) -c $^ -o $@

run:
	./$(EXECUTABLE)

clean:
	rm *.o
