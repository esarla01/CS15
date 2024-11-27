/*
 *  PassengerQueue
 *  Erin Sarlak
 *  February 15, 2021
 *
 *  CS 15 Proj1 Week1
 *
 *  This file contains the implementation of the PassengerQueue.
 *
 */
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"

/*
 * name:      front 
 * purpose:   Returns, but does not remove, the element at the front of the 
 *            queue
 * arguments: passenger
 * returns:   none
 * effects:   none
 */
Passenger PassengerQueue:: front(){
    return p_queue.front();
}


/*
 * name:      enqueue 
 * purpose:   Inserts a new passenger at the end of the queue
 * arguments: passenger
 * returns:   none
 * effects:   size increases by 1
 */
void PassengerQueue::enqueue(const Passenger &passenger){
    //adds the passenger at the end of the queue
    p_queue.push_back(passenger);
}


/*
 * name:      dequeue 
 * purpose:   Removes the element at the front of the queue
 * arguments: none
 * returns:   none
 * effects:   size decreases by 1
 */
void PassengerQueue::dequeue(){
    //removes the first passenger from the list
     p_queue.erase(p_queue.begin());
}


/*
 * name:      size 
 * purpose:   Returns the number of elements in the queue
 * arguments: none
 * returns:   none
 * effects:   none
 */
int PassengerQueue::size(){
    //returns the size of the queue
    return p_queue.size();
}


/*
 * name:      print 
 * purpose:   Prints each Passenger in the PassengerQueue to the given output
*             stream from front to back
 * arguments: output 
 * returns:   none
 * effects:   none
 */
void PassengerQueue::print(ostream &output){
    //prints each element in the queue  
    for (size_t i = 0; i < p_queue.size(); i++){
        p_queue[i].print(output);
    }
}

