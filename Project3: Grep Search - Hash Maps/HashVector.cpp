/*
 *  HashVector.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Implementation for HashVector:
 *  a vector in order to add the
 *  HashElements to as chosen collision
 *  handling way is chaining and there 
 *  could be different elements of the same
 *  lowercase word (where uppercase letters
 *  could be present in different ways)
 *
 */

#include <iostream>
#include <vector>

#include "HashVector.h"
#include "HashElement.h"

using namespace std;

// Purpose:      inserts element to the hash vector by either adding
//               to an already existing element or creating an
//               altogether new element
// Parameters:   HashElement to be added
// Returns:      
// Side effects: 
void HashVector::insert_element(HashElement toadd)
{
    // if chain is not empty and there is a matching element, add line and path
    if (not isempty()) {
        for (unsigned int i = 0; i < ChainList.size(); i++) {
            if (toadd.getoriginal() == ChainList[i].getoriginal()) {
                ChainList[i].addLinePath(toadd.getline(0), toadd.getpath(0));
                return;
            }
        }
    }
    // if chain is empty or if chain is not empty but no element matches word
    ChainList.push_back(toadd);
}

// Purpose:      gets access to a an element in the specific index of the vector
// Parameters:   index of the element in the vector
// Returns:      desired hashelement
// Side effects: 
HashElement HashVector::elementAt(int index)
{
    return ChainList[index];
}

// Purpose:      tells whether vector is empty or not
// Parameters:   
// Returns:      true if empty, false if not
// Side effects: 
bool HashVector::isempty()
{
    return ChainList.empty();
}

// Purpose:      gets size of given vector
// Parameters:   
// Returns:      size of vector
// Side effects: 
int HashVector::getSize()
{
    return ChainList.size();
}

// Purpose:      clears contents of vector
// Parameters:   
// Returns:      
// Side effects: 
void HashVector::clear()
{
    for (int i = 0; i < getSize(); i++) {
        ChainList.erase(ChainList.begin());
    }
}

// Purpose:      prints contents of a hash vector
//               useful for unit testing
// Parameters:   ostream for output to printed on
// Returns:      
// Side effects: 
void HashVector::print(std::ostream &output)
{
    for (unsigned int i = 0; i < ChainList.size(); i++) {
            ChainList[i].print(output);
    }
}
