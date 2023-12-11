/*
 *  unit_tests.h
 *  Erin Sarlak
 *  February 15, 2022
 *
 *  CS 15 PROJ1 
 * 
 *  This file contains the codes that test the functions of the 
*   Passeneger and PassengerQueue classes.
 *
 */

#include <iostream>
#include <ostream>
#include <string>
#include <cassert>
#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"

using namespace std;


/*
 * Passenger Print Test
 * Make sure that it prints the information about the instance of a passenger
 * correctly.
 */
void Passenger_Print_Test(){
    Passenger P1(3, 1, 5);
    //look for "[3, 1->5]" in the terminal
    P1.print(std::cout);
    
}


/*
 * Passenger Print Test
 * Make sure that it returns the number of elements in the queue.
 */
void Passenger_Print_Size(){
    PassengerQueue queue;
    Passenger P1(3, 1, 5);
    queue.enqueue(P1);
    assert(queue.size() == 1);

    Passenger P2(4, 2, 6);
    queue.enqueue(P2);
    assert(queue.size() == 2);
}


/*
 * PassengerQueue Front Test
 * Make sure that it returns, but does not remove, the element at the front of
 * the queue.
 */
void PassengerQueue_Front_Test(){
    PassengerQueue queue;
    Passenger P1(3, 1, 5);
    queue.enqueue(P1);
    Passenger P2(4, 2, 6);
    queue.enqueue(P2);

    //check if the front is the first element added to the queue
    queue.front().print(std::cout);     //look for "[3, 1->5]"
    assert(queue.size() == 2);
}


/*
 * PassengerQueue Enqueue Test
 * Make sure that the function inserts the element at the end of the queue.
 */
void PassengerQueue_Enqueue_Test(){
    PassengerQueue queue;
    Passenger P1(3, 1, 5);
    queue.enqueue(P1);
    Passenger P2(4, 2, 6);
    queue.enqueue(P2);

    //check if the the passengers are added to the queue
    queue.print(std::cout);      //look for "[3, 1->5] [4, 2->6]"
    assert(queue.size() == 2);
}


/*
 * PassengerQueue Dequeue Test
 * Make sure that it removes the element at the front of the queue.
 */
void PassengerQueue_Dequeue_Test(){
    PassengerQueue queue;
    Passenger P1(3, 1, 5);
    queue.enqueue(P1);
    Passenger P2(4, 2, 6);
    queue.enqueue(P2);

    queue.dequeue();
    //check if the the passenger is removed from the queue
    queue.print(std::cout);      //look for "[4, 2->6]"
    assert(queue.size() == 1);      

    queue.dequeue();
    assert(queue.size() == 0);
}


//////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Phase 2////////////////////////////////////

// /*
//  * Populate Station Test
//  * Make sure that it adds passengers to the train correctly
//  */
void populate_station_test(){

    Train test; 
    test.add_station("College Avenue");
    test.add_station("Ball Square");
    test.add_station("Magoun Square");
    test.populate_station(1, 0, 1);
    test.populate_station(2, 1, 2);
    test.populate_station(2, 1, 2);
    test.print_stations();

}


/*
 * Add Station Test
 * Make sure that it adds statios to the train and station queue and also
 * adds the names of the stations in name queue.
 */
void add_station_test(){
    Train test; 

    for (int i = 0; i < 200; i++) {
        test.add_station("station");
    }
    test.print_stations();
}


// /*
//  * Pick Up Passengers Test
//  * Make sure that the train picks the passengers from the departing station
//  * and removes them from the station queue.
//  */
void pick_up_passengers_test(){

    Train test; 
    test.add_station("College Avenue");
    test.add_station("Ball Square");
    test.add_station("Magoun Square");
    test.populate_station(1, 0, 1);
    test.populate_station(2, 1, 2);
    test.populate_station(2, 1, 2);
    test.pick_up_passengers();
    test.print_stations();
 
}


// /*
//  * Drop Passengers Test
//  * Make sure that the train drops the passengers at their final destination
//  */
void drop_passengers_test(){

    Train test; 
    test.add_station("College Avenue");
    test.add_station("Ball Square");
    test.add_station("Magoun Square");
    test.populate_station(1, 0, 1);
    test.populate_station(2, 1, 2);
    test.populate_station(2, 1, 2);
    //test.drop_passengers(std:::cout);
    test.print_stations();

}


// /*
//  * Update Train Position Test
//  * Make sure that the train's position increments unless it is at the last 
//  */
void update_train_position_test(){
    Train test; 
    test.add_station("College Avenue");
    test.add_station("Ball Square");
    test.add_station("Magoun Square");
    test.populate_station(1, 0, 1);
    test.populate_station(2, 1, 2);
    test.populate_station(2, 1, 2);
    test.update_train_position();
    test.print_stations();

}

//  * Update Train Position Test
//  * Make sure that if the train is at the last station, then it returns back
//  * to the first station.
//  */
void update_train_position_test2(){
    Train test; 
    test.add_station("College Avenue");
    test.add_station("Ball Square");
    test.add_station("Magoun Square");
    test.populate_station(1, 0, 1);
    test.populate_station(2, 1, 2);
    test.populate_station(2, 1, 2);
    test.update_train_position();
    test.print_stations();
    test.update_train_position();
    test.print_stations();
    test.update_train_position();
    test.print_stations();
}




