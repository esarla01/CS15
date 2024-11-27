/*
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"
#include "MetroSim.h"

/*
 * name:      MetroSim default constructor
 * purpose:   initialize the id of the first passenger
 * arguments: none
 * returns:   none
 * effects:   n_passenger(id) to 1
 */
MetroSim::MetroSim(){
    n_passenger = 1;
}


/*
 * name:      Initialize Station
 * purpose:   Reads the station names from the file and adds as mnay stations
 *            to the train and station queues as there are in the file
 * arguments: ifstream input (read from station file)
 * returns:   none
 * effects:   size of train and station queue increases and the name queue is 
 *            popullated with the names of the station queues 
 */
void MetroSim::initialize_station(std::ifstream &input) {

    std::string n_station;
    //read the station names in the file 
    while (getline(input, n_station)){
        //add the stations in the file to the station queue
        train.add_station(n_station);
    }
}


/*
 * name:      Move Train
 * purpose:   Moves the Train from the current Station to the next one in the 
 *            line. The train should move to the first Station if it is 
 *            currently at the last Station.
 * arguments: ifstream input (read from station file)
 * returns:   none
 * effects:   All Passengers at the departing Station will get on the train. 
 *            Any Passengers whose final destination is that Station will 
 *            exit the Train. 
 */
void MetroSim::move_train(std::ostream &output){
    //when the train moves, it picks up the passengers from the station, and
    //drops the passengers in inside the train that arrived their destination
    train.pick_up_passengers();
    train.update_train_position();
    train.drop_passengers(output);
}


/*
 * name:      Command Loop
 * purpose:   Takes in commands from the user and executes them. The commands
 *            are "p Arrival Departure", "m m", "m f."
 * arguments: ifstream input (read from station file)
 * returns:   none
 * effects:   moves along stations, picking up passengers from departing stations
 *            and dropping off passengers in the final destinations
 */
void MetroSim::command_loop(std::istream &input, std::ostream &output){
    char command, next; 
    int from, to;

    train.print_stations();
 
    std::cout << "Command? ";
    
    while(input >> command){

        if (command == 'p'){
            input>>from>>to;
            //add the passenger to the train 
            train.populate_station(n_passenger, from, to);
            n_passenger++; //tracks passenger ids
        }
        else if(command == 'm'){
            input>>next;
                if(next == 'm'){    //if the command is "m m"
                    //moves the train to the next station 
                    move_train(output);
                }
                else if(next == 'f'){  //if the commands if "m f"
                    //exits the program and prints the given message 
                    std::cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
                    return;
                }
        }
        train.print_stations();
        std::cout << "Command? ";
    }

     std::cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}
        







