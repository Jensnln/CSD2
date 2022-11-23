# Define the symbols we might want to change:
CXX	:= g++
CXXFLAGS := -g -Wall
OBJECTS	:= main.o test.o

my_program: $(OBJECTS)
	$(CXX) $(OBJECTS) -o my_program

main.o: main.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c main.cpp -o main.o

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o