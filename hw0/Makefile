<<<<<<< HEAD
CC?=gcc
CFLAGS?=-Wall
BINARIES=map limits

all: default
default: $(BINARIES)

%: %.c
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(BINARIES)
=======
all : wc main map clean
wc: wc.o
	gcc -ggdb3 wc.o -o wc
wc.o: wc.c
	gcc -ggdb3 -c wc.c
main: main.o 
	gcc -ggdb3 main.o -o main
main.o: main.c
	gcc -ggdb3 -c main.c
map: map.o
	gcc -ggdb3 map.o -o map
map.o: map.c 
	gcc -ggdb3 -c map.c 

clean: 
	rm -rf wc.o main.o map.o
>>>>>>> 44fd239bb128f59ae368d37c60a167875910ea8a
