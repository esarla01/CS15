/*
 *  HashVector.h
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Interface for HashVector:
 *  a vector in order to add the
 *  HashElements to as chosen collision
 *  handling way is chaining and there 
 *  could be different elements of the same
 *  lowercase word (where uppercase letters
 *  could be present in different ways)
 *
 */

#ifndef HASH_VECTOR_H
#define HASH_VECTOR_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "HashElement.h"

using namespace std;

class HashVector
{
public:
    void insert_element(HashElement tobeadded);
    void print(std::ostream &output);
    bool isempty();
    int getSize();
    HashElement elementAt(int index);
    void clear();
private:
    std::vector<HashElement> ChainList;
};

#endif