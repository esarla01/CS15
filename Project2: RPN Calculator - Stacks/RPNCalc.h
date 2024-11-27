/* PROJ2
 * Tansu Erin Sarlak
 * 05/01/2022
 * Interface for RPNCALC Class
 */

#ifndef _RPNCALC_H_
#define _RPNCALC_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "Datum.h"
#include "DatumStack.h"


class RPNCalc
{

public:

RPNCalc();

~RPNCalc();

void run();

private:

void is_true();

void is_false();

void is_not();

void is_swap();

void is_operation(std::string s_operation);

bool got_int(std::string s, int *resultp);

void play(std::istream &stream_name);

std::string parseRString(std::istream &stream_name);

void is_exec();

bool isRString();

void is_file();

void is_if();

DatumStack stack;

bool s_quit;
    
};

#endif
