#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 


MetroSim: main.o MetroSim.o Train.o PassengerQueue.o Passenger.o 
	$(CXX) $(CXXFLAGS) -o MetroSim $^

MetroSim.o: MetroSim.cpp MetroSim.h Train.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp


Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp


main.o: main.cpp MetroSim.h Train.h Passenger.h PassengerQueue.h
	$(CXX) $(CXXFLAGS) -c main.cpp


PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp


Train.o: Train.cpp Train.h PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c Train.cpp


unit_test: unit_test_driver.o MetroSim.o Train.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) $^


provide:
	provide comp15 proj1_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
					Train.h Train.cpp \
					MetroSim.h MetroSim.cpp \
					main.cpp stations.txt\
					outputfile.txt test_commands.txt \
					addpassengers.txt emptyfile.txt \
					movetrain.txt \
				    unit_tests.h Makefile README

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
