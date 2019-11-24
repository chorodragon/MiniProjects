CC = gcc
OBJECTIVE = hashTable
CFLAGS = -Wall -Wextra 
SOURCE = hashTable.c
OBJECTS = hashTable.o

$(OBJECTIVE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OBJECTIVE)

%.o:%.c
	$(CC) $(CFLAGS) -c $<
