CC = g++
CFLAGS = -Wall
SRC = main.cpp StringVector.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main
EXE = shallow-copy

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

$(EXE): shallow-copy.o
	$(CC) $(CFLAGS) -o $@ $^

all:$(TARGET) $(EXE)

run:$(TARGET)
	./$(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) $(EXE)