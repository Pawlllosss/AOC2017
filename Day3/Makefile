CXX = g++
CXXFlags = -Wall -Wextra -pedantic -g

all: Day3

Day3: Main.o SpiralMem.o
	$(CXX) $^ -o $@

Main.o: Main.cpp SpiralMem.h
	$(CXX) $(CXXFlags) -c $<

SpiralMem.o: SpiralMem.cpp SpiralMem.h
	$(CXX) $(CXXFlags) -c $<

.PHONY : clean

clean: 
	rm -rf *.o Day3
