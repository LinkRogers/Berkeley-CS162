SRCS = hello.c
EXECUTABLES=hello

CC = gcc
CFLAGS=-g -Wall 
LDFLAGS= -pthread

OBJS=$(SRCS:.c=.o)
all: $(EXECUTABLES)

$(EXECUTABLES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -rf $(EXECUTABLES) $(OBJS)
