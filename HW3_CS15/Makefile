#
# Makefile for Binary Search Tree
#
# Homework 3 (fall 2021)
#

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 
LDFLAGS  = -g3


hw3: hw3.o BinarySearchTree.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

unit_test: unit_test_driver.o BinarySearchTree.o 
	${CXX} ${LDFLAGS} unit_test_driver.o BinarySearchTree.o

clean:
	rm -rf hw3 *.o *.dSYM

# Don't forget to add your testing files to this rule if you use it!
provide:
	provide comp15 hw3_BST hw3.cpp BinarySearchTree.cpp BinarySearchTree.h \
			my_output comp_output README Makefile
	        

