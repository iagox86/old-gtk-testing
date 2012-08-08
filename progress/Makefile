CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags gtk+-2.0`
LIBS = `pkg-config --libs gtk+-2.0`

all: main.o
	${CC} ${CFLAGS} ${LIBS} main.o -o main

