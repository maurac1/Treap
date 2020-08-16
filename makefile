CXX = g++
CXXFLAGS = -O0

all: test-1 test0 test1 test2 test3 test4

test-1: treap.o driver.cpp
	$(CXX) $(CXXFLAGS) treap.o driver.cpp -o test-1

test0: treap.o test0.cpp
	$(CXX) $(CXXFLAGS) treap.o test0.cpp -o test0

test1: treap.o test1.cpp
	$(CXX) $(CXXFLAGS) treap.o test1.cpp -o test1

test2: treap.o test2.cpp
	$(CXX) $(CXXFLAGS) treap.o test2.cpp -o test2

test3: treap.o test3.cpp
	$(CXX) $(CXXFLAGS) treap.o test3.cpp -o test3

test4: treap.o test4.cpp
	$(CXX) $(CXXFLAGS) treap.o test4.cpp -o test4

treap.o: treap.h treap.cpp print.h
	$(CXX) $(CXXFLAGS) -c treap.cpp

submit:
	cp treap.h treap.cpp ~/cs341proj/proj3/