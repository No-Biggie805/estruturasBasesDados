# rm: fase1.o meio.o
# 	rm fase1.o meio.o

# fase1: fase1.o meio.o
# 	gcc -o fase1 fase1.o meio.o

# fase1.o meio.o: fase1.c meio.c
# 	gcc -c fase1.c meio.c

CC=gcc
CFLAGS=-Wall -g

#insert other .c here:
SOURCES=main.c meios.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
