
CC = g++
CFLAGS = -Wall

SRC = main.cpp Fraction.cpp StringVector.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o *.exe

.PHONY: all clean