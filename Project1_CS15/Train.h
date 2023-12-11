/*
 *  Train.h
 *  Erin Sarlak
 *  February 20, 2021
 *
 *  CS 15 Proj1
 *
 *  This file contains the interface of the Train class.
 *
 */

#ifndef _TRAIN_H_
#define _TRAIN_H_

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;


class Train{

public:

Train();

void pick_up_passengers();

void drop_passengers(std::ostream &output);

void update_train_position();

void add_station(std::string s_name);

void populate_station(int n_passenger, int from, int to);

void print_stations();


private:    

std::vector<PassengerQueue>p_queuestation;
std::vector <std::string> p_queuename;
std::vector<PassengerQueue>p_queuetrain;
int position;

};
#endif