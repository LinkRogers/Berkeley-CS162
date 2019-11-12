<<<<<<< HEAD
CC=gcc
CFLAGS=-Wall -g -pthread
LD=-pthread
V2_DEFINE=-DPART2
V3_DEFINE=-DPART3
V4_DEFINE=-DPART4

COMMON_H_FILES=spooler.h
SPOOLER_C_FILE=spooler.c

EXECS=unit_tests spooler1 spooler2 spooler2_killed spooler3 spooler4

SHARED_OBJS=consumer.o producer.o spooler_shared.o

PART1_SHARED_OBJS=$(SHARED_OBJS) spooler_unsafe.o spooler_v1.o
PART1_OBJS=$(PART1_SHARED_OBJS) main.o
UNIT_TEST_OBJS=$(PART1_SHARED_OBJS) api_tests.o

PART2_SHARED_OBJS=$(SHARED_OBJS) spooler_safe.o spooler_v2.o
PART2_OBJS=$(PART2_SHARED_OBJS) main.o
PART2_KILLED_OBJS=$(PART2_SHARED_OBJS) main_killed.o

PART3_OBJS=$(SHARED_OBJS) spooler_one_cv.o main.o spooler_safe.o spooler_v3.o

PART4_OBJS=$(SHARED_OBJS) spooler_two_cv.o main.o spooler_safe.o spooler_one_cv.o spooler_v4.o

all: $(EXECS)

unit_tests: $(UNIT_TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LD)

spooler1: $(PART1_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LD)

spooler2: $(PART2_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LD)

spooler2_killed: $(PART2_KILLED_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LD)

spooler3: $(PART3_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LD)

spooler4: $(PART4_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LD)

spooler_v1.o: $(SPOOLER_C_FILE) $(COMMON_H_FILES)
	$(CC) $(CFLAGS) -o $@ -c $<

spooler_v2.o: $(SPOOLER_C_FILE) $(COMMON_H_FILES)
	$(CC) $(CFLAGS) $(V2_DEFINE) -o $@ -c $<

spooler_v3.o: $(SPOOLER_C_FILE) $(COMMON_H_FILES)
	$(CC) $(CFLAGS) $(V3_DEFINE) -o $@ -c $<

spooler_v4.o: $(SPOOLER_C_FILE) $(COMMON_H_FILES)
	$(CC) $(CFLAGS) $(V4_DEFINE) -o $@ -c $<

%.o: %.c $(COMMON_H_FILES)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECS) *.out

.PHONY: all
=======
CFLAGS=-g -Wall -std=c99 -D_POSIX_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -fPIC
TEST_CFLAGS=-Wl,-rpath=.
TEST_LDFLAGS=-ldl

all: hw3lib.so mm_test

hw3lib.so: mm_alloc.o
	gcc -shared -o $@ $^

mm_alloc.o: mm_alloc.c
	gcc $(CFLAGS) -c -o $@ $^

mm_test: mm_test.c
	gcc $(CFLAGS) $(TEST_CFLAGS) -o $@ $^ $(TEST_LDFLAGS)

clean:
	rm -rf hw3lib.so mm_alloc.o mm_test
>>>>>>> 44fd239bb128f59ae368d37c60a167875910ea8a
