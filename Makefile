#////////////////////////////// FILE HEADER ///////////////////////////////////
#/ 
#/ Title: Infinite Integer Makefile
#/ Files: InfiniteInt.h, InfiniteInt.cpp, demo.cpp, Makefile, README.md
#/ Course: CS 368, Spring 2020
#/
#/ Author: Matt Thompson
#/ Student ID: 9081263262
#/ Email: mathompson23@wisc.edu
#/ Lecturer's Name: Marc Renault
#/
#/ Online Sources:
#/ - https://stackoverflow.com/questions/4427738/allocate-memory-for-a-vector
#/
#/ - http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/
#/   en/cpp/language/as_operator.html
#/ 
#/ - https://stackoverflow.com/questions/4261589/how-do-i-split-an-int-into
#/   -its-digits
#/
#/ - https://stackoverflow.com/questions/9438209/for-every-character-in-string
#/
#/ - https://stackoverflow.com/questions/28607912/sum-values-of-2-
#/   vectors/28607985
#/
#/ - https://www.geeksforgeeks.org/adding-one-to-number-represented-
#/   as-array-of-digits/
#/
#/ - https://stackoverflow.com/questions/12239015/how-to-append-an-integer
#/   -with-an-integer-in-c/12239029
#/
#/////////////////////////// FILE DESCRIPTION /////////////////////////////////
#/ 
#/ This is the makefile for demo.cpp, which displays the InfiniteInt program.
#/
#//////////////////////////////////////////////////////////////////////////////

# Makefile

CXX=g++
CXXFLAGS=-Wall

all: build

InfiniteInt.o: InfiniteInt.h

clean:
	-rm InfiniteInt.o
	-rm demo

build: demo.cpp InfiniteInt.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp InfiniteInt.o