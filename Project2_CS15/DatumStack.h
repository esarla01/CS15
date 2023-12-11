/* PROJ2
 * Tansu Erin Sarlak
 * 04/01/2022
 * Interface for DatumStack Class
 */

#ifndef _DATUMSTACK_H_
#define _DATUMSTACK_H_

#include <iostream>
#include <vector>
#include "Datum.h"

class DatumStack
{

public:
    DatumStack();

    DatumStack( Datum arr[], int size);

    bool isEmpty();

    void clear();

    int size();

    Datum top();

    void pop();

    void push(Datum element);

    //void print();
private:
    std::vector<Datum> stack;   
};

#endif
