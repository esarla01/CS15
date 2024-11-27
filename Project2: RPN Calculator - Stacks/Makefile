###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Tansu Erin Sarlak

# to have make follow symlinks in dependency lists
MAKEFLAGS += -L 

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

#program compiling rule
CalcYouLater: main.o RPNCalc.o DatumStack.o Datum.o
	$(CXX) $(CXXFLAGS) -o CalcYouLater $^

# main rule
main.o: main.cpp RPNCalc.h DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# DatumStack rule
DatumStack.o: DatumStack.cpp DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp

# RPNCalc rule
RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp

# unit_test rule
unit_test: unit_test_driver.o DatumStack.o Datum.o
	$(CXX) $(CXXFLAGS) $^

# rule for compiling .cyl files for use in your testing
%.cylc:  %.cyl
	./cylc $^

# rule that provides submission 
provide:
	provide comp15 proj2_calcyoulater DatumStack.h \
					DatumStack.cpp \
					main.cpp \
					RPNCalc.h \
					RPNCalc.cpp \
					got_int.cpp \
					parser.cpp \
					README \
					Makefile \
					simpleCommand_test.cylc \
					hardCommand_test.cylc \
					edgeCases_test.cylc \
					unit_tests.h