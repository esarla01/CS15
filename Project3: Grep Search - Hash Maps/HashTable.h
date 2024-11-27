/*
 *  HashTable.h
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Interface for HashTable:
 *  a hash where each index is calculated
 *  through a hash function and consists
 *  of a vector as chosen collision handling
 *  way is chaining
 *
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <functional>

#include "HashVector.h"
#include "HashElement.h"

using namespace std;

class HashTable
{
public:
    HashTable();
    void inserttotable(HashElement s);
    void clear();
    void expand();
    void print(ostream &output);
    bool checkload();
    string getKeyIn(int index, int no);
    string getOriginalIn(int index, int no);
    string getPathIn(int index, int no, int num);
    int getLineIn(int index, int no, int num);
    int getCountNum(int index, int no);
    int getSize(int index);
    int size();
private:
    vector <HashVector> table;
    int numElements;
};

#endif