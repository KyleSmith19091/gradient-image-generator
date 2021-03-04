CC = g++
CFLAGS = -Wall
VERSION = 11

run:
	$(CC) $(CFLAGS) -std=c++$(VERSION) ./src/*.cpp -I ./include -o main
	./main > ./res/image.ppm 

open-image:
	open ./res/image.ppm

create-image:
	g++ -std=c++11 ./src/*.cpp -I ./include -o main
	./main > ./res/image.ppm
	open ./res/image.ppm

make-png:
	mv ./res/image.ppm image.png
	mv image.png ./images
