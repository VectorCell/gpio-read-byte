ifeq ($(CXX), clang)
	COVFLAGS := --coverage
	GCOV     := gcov-4.6
else
	CXX      := gcc
	COVFLAGS := -fprofile-arcs -ftest-coverage
	GCOV     := gcov-4.8
endif

CXXFLAGS := -pedantic -std=c99 -Wall

main : main.o makefile
	$(CXX) $(CXXFLAGS) -o main main.o -lwiringPi
	rm -f *.d
	rm -f *.o

%.o : %.c makefile
	$(CXX) $(CXXFLAGS) -MD -c $*.c

test : makefile main
	sudo ./main

clean :
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.d
	rm -f *.o
	rm -f main

-include *.d
