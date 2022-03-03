CC=g++
CFLAGS=-c -Wall

all: main

main: main.o CFrequencyDictionary.o Utils.o
	$(CC) main.o CFrequencyDictionary.o Utils.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

CFrequencyDictionary.o: CFrequencyDictionary.cpp CFrequencyDictionary.h
	$(CC) $(CFLAGS) CFrequencyDictionary.cpp

Utils.o: Utils/Utils.cpp Utils/Utils.h
	$(CC) $(CFLAGS) Utils/Utils.cpp

clean:
	rm -rf *.o main
