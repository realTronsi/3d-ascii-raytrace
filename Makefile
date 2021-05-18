CC = gcc
CFLAGS = -Wall -g

TARGET = out

C_SOURCE := $(shell find src -name *.c)

all:
	$(CC) $(CFLAGS) $(C_SOURCE) -o $(TARGET) -lm
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf *.o