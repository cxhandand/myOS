CC = gcc
CFLAGS = -Wall -Wextra

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)