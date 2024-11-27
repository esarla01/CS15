###
### Makefile for GERP Project
### GERP is a basic grep-like manager that searchs
### words in given directory and prints instances
### of that word to a given file
###
### Author: Tansu Erin Sarlak Ayse Idil Kolabas

MAKEFLAGS += -L 

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
OFLAG    = -O3
LDFLAGS  = -g3 

gerp: main.o gerp.o HashTable.o HashVector.o HashElement.o FSTree.o DirNode.o
	$(CXX) $(CXXFLAGS) $(OFLAG) -o gerp $^

gerp.o: gerp.cpp gerp.h HashTable.h HashVector.h HashElement.h FSTree.h \
															   DirNode.h
	$(CXX) $(CXXFLAGS) $(OFLAG) -c gerp.cpp 

HashTable.o: HashTable.cpp HashTable.h HashVector.h HashElement.h
	$(CXX) $(CXXFLAGS) $(OFLAG) -c HashTable.cpp 

HashVector.o: HashVector.cpp HashVector.h HashElement.h
	$(CXX) $(CXXFLAGS) $(OFLAG) -c HashVector.cpp

HashElement.o: HashElement.cpp HashElement.h 
	$(CXX) $(CXXFLAGS) $(OFLAG) -c HashElement.cpp

treeTraversal: FSTreeTraversal.o FSTree.o DirNode.o
	$(CXX) $(CXXFLAGS) $(OFLAG) -o treeTraversal $^

# tree traversal rule
FSTreeTraversal.o: FSTreeTraversal.cpp FSTree.h DirNode.h
	$(CXX) $(CXXFLAGS) $(OFLAG) -c FSTreeTraversal.cpp

# string processing rule
stringProcessing.o: stringProcessing.cpp stringProcessing.h
	$(CXX) $(CXXFLAGS) $(OFLAG) -c stringProcessing.cpp

# unit_test rule
unit_test: unit_test_driver.o stringProcessing.o HashElement.o HashVector.o \
									  HashTable.o gerp.o DirNode.o FSTree.o
	$(CXX) $(CXXFLAGS) $(OFLAG) $^

#rule for cleaning all executed files
clean:
	rm stringProcessing.o FSTreeTraversal.o treeTraversal gerp.o \
	                 HashTable.o HashVector.o HashElement.o gerp

# rule that provides submission 
provide:
	provide comp15 proj3_gerp FSTreeTraversal.cpp \
	                                 stringProcessing.h \
									 stringProcessing.cpp \
									 unit_tests.h \
									 Makefile \
									 gerp.cpp \
									 gerp.h \
									 HashElement.cpp \
									 HashElement.h \
									 HashVector.cpp \
									 HashVector.h \
									 HashTable.cpp \
									 HashTable.h \
									 main.cpp \
									 README \
									 commands1.txt \
									 commands2.txt \
									 commands3.txt \
									 commands4.txt \
									 commands5.txt \
									 our_cout1.txt \
									 our_cout2.txt \
									 our_cout3.txt \
									 our_cout4.txt \
									 ref_cout1.txt \
									 ref_cout2.txt \
									 ref_cout3.txt \
									 ref_cout4.txt \
									 our_outs1.txt \
									 our_outs2.txt \
									 our_outs3.txt \
									 our_outs4.txt \
									 ref_outs1.txt \
									 ref_outs2.txt \
									 ref_outs3.txt \
									 ref_outs4.txt \
									 our_newoutput.txt \
									 ref_newoutput.txt \
									 our_newestoutputs.txt \
									 ref_newestoutputs.txt
