CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS = $(wildcard *.c)
TARGET = hsh

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
