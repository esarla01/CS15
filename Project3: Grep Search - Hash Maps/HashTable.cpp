/*
 *  HashTable.cpp
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  Implementation for HashTable:
 *  a hash where each index is calculated
 *  through a hash function and consists
 *  of a vector as chosen collision handling
 *  way is chaining
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <functional>
#include <cctype>
#include <iomanip>

#include "HashTable.h"
#include "HashVector.h"
#include "HashElement.h"

using namespace std;

// Purpose:      constructs empty hash table 
//               with 2 empty lists to add to
// Parameters:   
// Returns:      
// Side effects: 
HashTable::HashTable()
{
        numElements = 0;
        HashVector list;
        // add two unassigned chains to the hashtable
        for (int i = 0; i < 100000; i++) {
                table.push_back(list);
        }
}

// Purpose:      inserts to the table
// Parameters:   hash element to be added to the table
// Returns:      
// Side effects: increments number of elements in the table
void HashTable::inserttotable(HashElement s)
{
        // check for the load factor 
        if (checkload()){
                expand();
        }

        // calculate hash number and put the word in the appropriate index
        int hash_num = hash <string> {} (s.getkey()) % table.size();
        table[hash_num].insert_element(s);
        numElements++;
}

// Purpose:      checks how full the table is by comparing
//               number of elements and number of buckets
// Parameters:   
// Returns:      true if threshold reached, false if not
// Side effects: 
bool HashTable::checkload()
{
        // use size as capacity since declared lists are important
        // rather than empty slots in the hash table
        double capac = table.size();
        double loadfactor = numElements / capac;
        return (loadfactor >= 0.7);
}

// Purpose:      expands the vector by adding new empty lists
//               and rehashing already existing elements
// Parameters:   
// Returns:      
// Side effects: 
void HashTable::expand()
{
        //store all the hash elements in a vector
        vector <HashElement> temp;
        for (unsigned int i = 0; i < table.size(); i++) {
            for (int j = 0; j < table[i].getSize(); j++){
                if (not table[i].isempty())
                    temp.push_back(table[i].elementAt(j));
            }
        }

        //determine a new size for the hash table
        int newTableSize = table.size()*2+1;

        //clear the table
        clear();

        // declares new empty lists in the hash
        HashVector list;
        for (int i = 0; i < newTableSize; i++) {
                table.push_back(list);
        }

        // rehashes the contents according to updated capacity
        for (unsigned int i = 0; i < temp.size(); i++) {
            int hash_num= hash<string>{} (temp[i].getkey()) % table.size();
                table[hash_num].insert_element(temp[i]);
        }

}

// Purpose:      prints contents of a hash table
//               useful for unit testing
// Parameters:   ostream for output to printed on
// Returns:      
// Side effects: 
void HashTable::print(std::ostream &output)
{
    for (unsigned int i = 0; i < table.size(); i++) {
            if (not table[i].isempty()){
                 output << endl << "Table index: " << i << " " << endl;
                 output << "-----------------" << endl;
            }
            table[i].print(output);
    }
    output << "-----------------" << endl;
}

// Purpose:      clears table
// Parameters:   
// Returns:      
// Side effects: 
void HashTable::clear()
{
        // clears contents of each vector in indices
        for (unsigned int i = 0; i < table.size(); i++){
                table[i].clear();
        }
        
        int sizefornow = table.size();
        
        // clears content
        for (int i = 0; i < sizefornow; i++) {
                table.pop_back();
        }    
}

// Purpose:      gets key of an element in the given index
//               of hash and in the given no index of the
//               vector inside it
// Parameters:   indices of hashtable and hashvector the
//               element is in
// Returns:      the desired key
// Side effects: 
string HashTable::getKeyIn(int index, int no)
{
        return table[index].elementAt(no).getkey();
}

// Purpose:      gets original form of an element in the 
//               given index of hash and in the given no
//               index of the vector inside it
// Parameters:   indices of hashtable and hashvector the
//               element is in
// Returns:      the desired original form
// Side effects: 
string HashTable::getOriginalIn(int index, int no)
{
        return table[index].elementAt(no).getoriginal();
}

// Purpose:      gets path of a given form of an element
//               in the given index of hash and in the
//               given no index of the vector inside it
// Parameters:   indices of hashtable and hashvector the
//               element is in and the num to see which
//               form of word is desired
// Returns:      the desired path
// Side effects: 
string HashTable::getPathIn(int index, int no, int num)
{
       return table[index].elementAt(no).getpath(num);
}

// Purpose:      gets line number of a given form of an
//               element in the given index of hash and
//               in the given no index of the vector inside it
// Parameters:   indices of hashtable and hashvector the
//               element is in and the num to see which
//               form of word is desired
// Returns:      the desired line number
// Side effects: 
int HashTable::getLineIn(int index, int no, int num)
{
        return table[index].elementAt(no).getline(num);
}

// Purpose:      gets number of forms of an element in the 
//               given index of hash and in the given no
//               index of the vector inside it
// Parameters:   indices of hashtable and hashvector the
//               element is in
// Returns:      the number of desired elements
// Side effects: 
int HashTable::getCountNum(int index, int no)
{
        return table[index].elementAt(no).getcount();
}

// Purpose:      gets size of the vectors inside a specific
//               index of the hash
// Parameters:   index of the hash to look at the vector
// Returns:      size of vector in the given index of hash
// Side effects: 
int HashTable::getSize(int index) {
        return table[index].getSize();
}

// Purpose:      gets size of table
// Parameters:   
// Returns:      
// Side effects: 
int HashTable::size() {
        return table.size();
}