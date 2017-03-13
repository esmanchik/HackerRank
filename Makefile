all: test

test: test.cpp
	g++ -g -std=c++11 test.cpp -o test

clean:
	rm -f jfc_track test
