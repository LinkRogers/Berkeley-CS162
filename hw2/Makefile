<<<<<<< HEAD
SRCS=shell.c tokenizer.c
EXECUTABLES=shell

CC=gcc
CFLAGS=-g -Wall -std=gnu99
LDFLAGS=-pthread

OBJS=$(SRCS:.c=.o)

all: $(EXECUTABLES)

$(EXECUTABLES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

threads:
	$(CC) $(CFLAGS) threads.c $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXECUTABLES) $(OBJS)
=======
CC=gcc
CFLAGS=-ggdb3 -c -Wall -std=gnu99
LDFLAGS=-pthread
SOURCES=httpserver.c libhttp.c wq.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=httpserver

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
>>>>>>> 44fd239bb128f59ae368d37c60a167875910ea8a
