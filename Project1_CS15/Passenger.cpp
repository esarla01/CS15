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
#include <string>
#include "Passenger.h"


/*
 * name:      prints the passenger
 * purpose:   the ostream that the output will be printed on
 * arguments: ostream output
 * returns:   none
 * effects:   none
 */
void Passenger::print(std::ostream &output)
{
       //prints passenger information
        output << "[" << this->id << ", " 
               << this->from << "->" 
               << this->to << "]";
}
