CC=clang++ -std=c++11
CFLAG=-Ilib/boost_1_75_0/stage/include
LIBS=-Llib/boost_1_75_0/stage/lib -lboost_unit_test_framework

vec3_test.out: vec3.h vec3_test.cpp
	$(CC) $(CFLAG) $(LIBS) vec3_test.cpp -o vec3_test.out

test: vec3_test.out
	DYLD_LIBRARY_PATH=./lib/boost_1_75_0/stage/lib ./vec3_test.out

clean:
	rm *.out