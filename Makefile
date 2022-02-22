CC = gcc
SRC = src/main.c src/networking.c src/utils.c src/render.c
LIBS = -lcurl -pthread
TARGET = zerobuster
CFLAGS += -g -pedantic -Wall


all: $(SRC)
	$(CC) $(SRC) $(LIBS) $(CFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)

.PHONY: all clean
