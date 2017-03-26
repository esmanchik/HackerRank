all: test test2

test: test.cpp
	g++ -g -std=c++11 test.cpp -o test

test2: test2.cpp
	g++ -g -std=c++11 test2.cpp -o test2

clean:
	rm -f test test2
