
# Compiler and flags
CC = g++
CXXFLAGS = -std=c++11 -fno-elide-constructors -Wall
OPTIMIZE_FLAGS = -O0

# Source and object files
SRC = redundant-constructor.cpp StringVector.cpp main.cpp emplace_back.cpp
OBJ = $(SRC:.cpp=.o)

EXE1 = redundant-constructor
EXE2 = emplace_back
MAIN_EXE = main

# Default target
all: $(EXE1) $(EXE2) $(MAIN_EXE)

# Linking the executable
$(EXE1): redundant-constructor.o StringVector.o
	$(CC) $(CXXFLAGS) $(OPTIMIZE_FLAGS) -o $@ $^

$(EXE2): emplace_back.o
	$(CC) -std=c++17 $(OPTIMIZE_FLAGS) -o $@ $^


$(MAIN_EXE): main.o StringVector.o
	$(CC) $(CXXFLAGS) $(OPTIMIZE_FLAGS) -o $@ $^


# Compile .cpp files into .o files
%.o: %.cpp
	$(CC) $(CXXFLAGS) $(OPTIMIZE_FLAGS) -c $< -o $@

emplace_back.o: emplace_back.cpp
	$(CC) -Wall -std=c++17 -c $< -o $@

# Clean up generated files
clean:
	rm -f *.o *.exe

# Phony targets 
.PHONY: all clean