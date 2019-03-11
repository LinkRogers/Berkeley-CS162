all : hello fork stack heap print10 wait FF exe clean
exe: exe.o
	gcc -ggdb3 exe.o -o exe
exe.o: exe.c
	gcc -ggdb3 -c exe.c
FF: FF.o
	gcc -ggdb3 FF.o -o FF
FF.o: FF.c
	gcc -ggdb3 -c FF.c
wait: wait.o
	gcc -ggdb3 wait.o -o wait
wait.o: wait.c
	gcc -ggdb3 -c wait.c
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
heap: heap.o
	gcc -ggdb3 heap.o -o heap
heap.o: heap.c
	gcc -ggdb3 -c heap.c 
print10: print10.o
	gcc -ggdb3 print10.o -o print10
print10.o: print10.c
	gcc -ggdb3 -c print10.c
clean: 
	rm -rf hello.o fork.o stack.o heap.o print10.o wait.o FF.o exe.o
