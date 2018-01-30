CXX = g++
CXXFlags = -Wall -Wextra -pedantic -g

all: Day1

Day1: Main.o List.o
	$(CXX) $^ -o $@

Main.o: Main.cpp List.h
	$(CXX) $(CXXFlags) -c $<

List.o: List.cpp List.h
	$(CXX) $(CXXFlags) -c $<

.PHONY : clean

clean: 
	rm -rf *.o Day1
