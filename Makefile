CC = gcc
SRC = src/main.c
LIBS = -lcurl -pthread
TARGET = zerobuster
CFLAGS += -g -pedantic -Wall


all: $(SRC)
	$(CC) $(SRC) $(LIBS) $(CFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)

.PHONY: all clean
