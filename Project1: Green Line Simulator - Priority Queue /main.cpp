/*
 *  
 *  Erin Sarlak
 *  February 23, 2021
 *
 *  CS 15 Proj1 Week2
 *
 *  This file contains the main for my MetroSim program.
 *
 */

#include <iostream>
#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

template<typename streamtype>
void open_or_die(streamtype &stream, string file_name);

int main(int argc, char *argv[]){

        if ((argc !=3) and (argc !=4) ){
                cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]" 
                << endl;
             exit(EXIT_FAILURE);
        }

        ifstream input;
        ofstream output;

        //opends the related files
        open_or_die(input, argv[1]);
        open_or_die(output, argv[2]);

        //creates an instance of MetroSim and  
        //initiazlizes train and station queue.
        MetroSim metrosim;
        metrosim.initialize_station(input);
        input.close();

        //if a file name is entered in the command line
        if (argc == 4) {
                open_or_die(input, argv[3]);
                metrosim.command_loop(input, output); 
        //if a file name is absent in the command line
        } else {
                metrosim.command_loop(std::cin, output);
        }
        
        input.close();
        output.close();

    return 0;    
}

//opens the given files and prints an error if file cannot be opened.
template<typename streamtype>
void open_or_die(streamtype &stream, string file_name)
{
    stream.open(file_name);
        if (not stream.is_open()) {
                cerr << "Error: could to open file " << file_name; 
                abort();
        }
}


