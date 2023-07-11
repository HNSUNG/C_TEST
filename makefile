CC = gcc
CFLAGS = -Wall -Wextra -DDEBUG

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
EXEC := test

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
