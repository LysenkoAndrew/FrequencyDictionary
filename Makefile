CC=g++
CFLAGS=-c -Wall

all: main

main: main.o CFrequencyDictionary.o
	$(CC) main.o CFrequencyDictionary.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

CFrequencyDictionary.o: CFrequencyDictionary.cpp CFrequencyDictionary.h
	$(CC) $(CFLAGS) CFrequencyDictionary.cpp


clean:
	rm -rf *.o main
