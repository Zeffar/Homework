CC = g++
CFLAGS = -Wall -O2 -std=c++23
FILE = euclid.cpp

all: build

build: ./$(FILE)
	$(CC) $(CFLAGS) $(FILE) -o build 
	./build
	rm build
	

clean:
	rm build