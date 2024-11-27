/*
 *  PassengerQueue.h
 *  Erin Sarlak
 *  February 15, 2021
 *
 *  CS 15 Proj1
 *
 *  This file contains the interface of the PassengerQueue class.
 *
 */

#ifndef _PASSENGERQUEUE_H_
#define _PASSENGERQUEUE_H_

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include "Passenger.h"

using namespace std;

class PassengerQueue
{
public:
    Passenger front();

    void dequeue();

    void enqueue(const Passenger &passenger);

    int size();

    void print(ostream &output);

private:
    std::vector<Passenger>p_queue;

};

#endif
