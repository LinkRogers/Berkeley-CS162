SRCS = spacex.c hello.c 
EXECUTABLES= $(SRCS:.c=)

CC = gcc
CFLAGS=-g -Wall 
LDFLAGS= -pthread

OBJS=$(SRCS:.c=.o)
all: $(EXECUTABLES)

$(EXECUTABLES): % : %.o
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -rf $(EXECUTABLES) $(OBJS)
