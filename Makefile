CC=clang++ -std=c++11
CFLAG=-Ilib/boost_1_75_0/stage/include
LIBS=-Llib/boost_1_75_0/stage/lib -lboost_unit_test_framework

main: color.h vec3.h
	$(CC) main.cc -o main

vec3_test.out: vec3.h vec3_test.cpp
	$(CC) $(CFLAG) $(LIBS) vec3_test.cpp -o vec3_test.out

color_test.out: vec3.h color.h color_test.cpp
	$(CC) $(CFLAG) $(LIBS) color_test.cpp -o color_test.out

test: vec3_test.out color_test.out
	DYLD_LIBRARY_PATH=./lib/boost_1_75_0/stage/lib ./vec3_test.out
	DYLD_LIBRARY_PATH=./lib/boost_1_75_0/stage/lib ./color_test.out

clean:
	rm *.out
