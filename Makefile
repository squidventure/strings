target: all

all: benchmarks tests

benchmarks:
	g++ -o strings_benchmarks strings_benchmarks.cpp -std=c++2a -lpthread -lbenchmark

tests:
	g++ -o strings_tests strings_tests.cpp -std=c++2a -lgtest -lpthread -lgtest

clean:
	rm -f strings_tests strings_benchmarks