CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c binary_tree.c functions.c
OBJ = $(SRC:.c=.o)

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c binary_tree.h functions.h
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all
