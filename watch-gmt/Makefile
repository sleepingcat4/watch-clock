CC = gcc
CFLAGS = -Wall -g

all: watch-gmt

watch-gmt: src/watch-live.c
	$(CC) $(CFLAGS) -o watch-gmt src/watch-live.c

clean:
	rm -f watch-gmt

