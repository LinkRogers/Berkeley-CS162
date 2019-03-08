all : hello fork stack clean
hello: hello.o
	gcc -ggdb3 hello.o -o hello
hello.o: hello.c
	gcc -ggdb3 -c hello.c
fork: fork.o
	gcc -ggdb3 fork.o -o fork
fork.o: fork.c
	gcc -ggdb3 -c fork.c
stack: stack.o
	gcc -ggdb3 stack.o -o stack
stack.o: stack.c
	gcc -ggdb3 -c stack.c
clean: 
	rm -rf hello.o fork.o stack.o
