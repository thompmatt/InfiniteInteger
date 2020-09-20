# Infinite Integer

The Infinite Integer program is a operator overload based program that constructs an infinitely large unsigned number, that is represented as a vector of unsigned integers. Every digit in said Infinite Integer occupies one index in the vector. This program has a variety of constructors for the Infinite Integer object, i.e. taking in another number (long long) or a new vector of unsigned integers. Furthermore, the program includes 17 overloaded operators that do a variety of basic arithmetic computations and/or comparations, such as addition, subtraction, less than, more than, among others.

## Organization

The code is organized into three files: InfiniteInt.h, InfiniteInt.cpp and demo.cpp. This program also includes a Makefile. Inside the InfiniteInt.h header file one can find all the method headers, and the InfiniteInt class and functions which are included but not defined. The InfiniteInt.cpp file includes the header file and defines all the function bodies, going into detail on how they all work and containing all the algorithms. Finally, demo.cpp runs the main method, which displays all of the functions included in the InfiniteInt.cpp file.

## Compiling and running code

To compile the code:
- Open Terminal
- Navigate towards the location of the files / Makefile.
- Type "make" onto the terminal.

To run the code:
- After compiling, type "./demo"

## Author

* **Matt Thompson** - *Infinite Integer*