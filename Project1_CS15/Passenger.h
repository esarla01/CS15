/*
 *  Passenger.h
 *  Erin Sarlak
 *  February 15, 2021
 *
 *  CS 15 Proj1
 *
 *  This file contains the interface of the Passenger class.
 *
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        
        void print(std::ostream &output);

};

#endif
