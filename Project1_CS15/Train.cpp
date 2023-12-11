/*
 *  Train
 *  Erin Sarlak
 *  February 20, 2021
 *
 *  CS 15 Proj1 Week1
 *
 *  This file contains the implementation of the Train.
 *
 */
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"

/*
 * name:      Train default constructor
 * purpose:   initialize the position of the train
 * arguments: none
 * returns:   none
 * effects:   train position to 0 
 */
Train::Train() {
    position = 0;
}


/*
 * name:      Pick Up Passengers
 * purpose:   Adds all the passengers at the departing station to the train
 *            and removes them from the station
 * arguments: none
 * returns:   none
 * effects:   updates the station and the train
 */
void Train::pick_up_passengers(){

    while (not (p_queuestation[position].size() == 0)){
        Passenger passenger = p_queuestation[position].front();
        //add passengers to the train based on their destinations 
        p_queuetrain[passenger.to].enqueue(passenger);
        //remove passengers from the station as they get on the train
        p_queuestation[position].dequeue();
    }

}


/*
 * name:      Drop Passengers
 * purpose:   Removes the passengers who have arrived their destination station from the train 
 * arguments: ostream output (an empty file for the messages to be printed)
 * returns:   none
 * effects:   For each Passenger that exits at a Station, the following line is written to the 
 *            output file: Passenger ID left train at station STATION_NAM
 */
void Train::drop_passengers(std::ostream &output){

    while (not (p_queuetrain[position].size() == 0)){
        //drop the passengers from the train who have arrived their destination
        Passenger temp = p_queuetrain[position].front();
        output << "Passenger " << temp.id << " left train at station "
                << p_queuename[position] << std::endl;
        p_queuetrain[position].dequeue();
    }

}


/*
 * name:      Update Train Position
 * purpose:   Increment the train's position unless it is at the last station;
 *            if this is the case, position reverts to 0 as the train circles 
 *            around.
 * arguments: none
 * returns:   none
 * effects:   position increases by 1 or becomes 0.
 */
void Train::update_train_position() {

    int temp = p_queuename.size() - 1;
    //if the train is at the last station, 
    //the train returns to the first station
    if (position == temp){
        position = 0;
    }
    //increments the position of the train
    else{
        position++;
    }

}


/*
 * name:      Add Station
 * purpose:   Adds a new empty passengerqueue in station and train queues 
 * arguments: name of the station (read from a file)
 * returns:   none
 * effects:   train, station, and name vectors increase in size by 1
 */
void Train::add_station(std::string s_name){

    //add the station name to the name queue
    p_queuename.push_back(s_name);
    PassengerQueue list;
    //add a new passengerqueue to  both the station and train queue
    p_queuestation.push_back(list);
    p_queuetrain.push_back(list);

}


/*
 * name:      Popuate Station
 * purpose:   Adds a passenger to the train based on the station that they
 *            board the train
 * arguments: passenger id, boarding station, departing station
 * returns:   none
 * effects:   train, station, and name vectors increase in size by 1
 */
void Train::populate_station(int n_passenger, int from, int to){
    //create a passenger based on the entered information
    Passenger P1(n_passenger, from, to);
    //add passengers to station queue based on their origin
    p_queuestation[from].enqueue(P1);

}


/*
 * name:      Print Stations
 * purpose:   Prints the train stations, the train at a station, and the 
 *            passengers in each station on terminal
 * arguments: none
 * returns:   none
 * effects:   none
 */
void Train::print_stations(){

    int station_size = p_queuestation.size();
    
    //prints the info of passengers in the train
    std::cout<<"Passengers on the train: {"; 
    for (int i = 0; i < station_size; i++){
       p_queuetrain[i].print(std::cout);
    }
    std::cout<<"}"<<std::endl;

    //prints the train stations and the passengers in each one of them
    for (int i = 0; i < station_size; i++){
        //prints the train in the station next to the station
        if (position == i){
        std::cout<<"TRAIN: ";
        }
        else{
            std::cout<<"       ";
        }
        //prints the information of the train stations
        std::cout<<"[" <<i<< "] "<<p_queuename[i];
        std::cout<< " {";
        p_queuestation[i].print(std::cout);
        std::cout<< "}"<<std::endl; 
   }
   
}




                                                