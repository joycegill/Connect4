CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lncurses -pthread
TARGET = connect4
SRC = main.c game.c ui.c
HEADERS = socket.h game.h ui.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean