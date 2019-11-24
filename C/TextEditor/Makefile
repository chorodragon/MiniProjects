CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
TARGET = kilo
SOURCE = kilo.c
OBJECTS = kilo.o

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)
	echo "DONE"

%.o:%.c
	$(CC) $(CFLAGS) -c $<
