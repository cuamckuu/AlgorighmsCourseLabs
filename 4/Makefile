.PHONY: all cls compile run clean test

CC=g++
CFLAGS=--std=c++11 -Wall
EXECUTABLE=project
SOURCES=main.cpp unit.cpp sortings.cpp binaryheap.cpp itterator.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: cls compile run clean

cls:
	clear

compile: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clean:
	rm *.o
