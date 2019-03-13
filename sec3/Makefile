all : stop handler writeAndSeek dup redirection redirection2 clean
redirection2: redirection2.o
	gcc -ggdb3 redirection2.o -o redirection2
redirection2.o: redirection2.c
	gcc -ggdb3 -c redirection2.c
redirection: redirection.o
	gcc -ggdb3 redirection.o -o redirection
redirection.o: redirection.c
	gcc -ggdb3 -c redirection.c
dup: dup.o
	gcc -ggdb3 dup.o -o dup
dup.o: dup.c
	gcc -ggdb3 -c dup.c
writeAndSeek: writeAndSeek.o
	gcc -ggdb3 writeAndSeek.o -o writeAndSeek
writeAndSeek.o: writeAndSeek.c
	gcc -ggdb3 -c writeAndSeek.c 
stop: stop.o
	gcc -ggdb3 stop.o -o stop
stop.o: stop.c
	gcc -ggdb3 -c stop.c
handler: handler.o
	gcc -ggdb3 handler.o -o handler
handler.o:handler.c
	gcc -ggdb3 -c handler.c
clean: 
	rm -rf stop.o handler.o writeAndSeek.o dup.o redirection.o redirection2.o
