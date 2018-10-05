.PHONY: all cls compile run clean test

CC=g++
CFLAGS=-std=c++11
EXECUTABLE=project
SOURCES=main.cpp list.cpp unit.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: cls compile run clean

cls:
	clear

compile: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(EXECUTABLE)

test:
	./$(EXECUTABLE) --test

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

list.o: list.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

unit.o: unit.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

run:
	./$(EXECUTABLE)

clean:
	rm *.o
