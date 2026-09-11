CC = gcc
CFLAGS = -Wall -Wextra -Isrc

SRC = src/codes/notefile.c
TARGET = notefile


all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)


clean:
	rm -f $(TARGET)
