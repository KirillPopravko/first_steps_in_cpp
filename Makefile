flags=-Wall -g -std=c++14 
programs=hello_world assignment1 assignment2

all: $(programs)

$(programs):
	clang++ FirstStepsInCPP/$@.cpp $(flags) -o Debug/$@ -IFirstStepsInCPP/book_headers/
