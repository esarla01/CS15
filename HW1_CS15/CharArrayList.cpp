/*
 *  CharArrayList.cpp
 *  Erin Sarlak
 *  January  28, 2022
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Creating an array list.
 *
 */

#include "CharArrayList.h"
#include <string>
#include <stdexcept>
#include <iostream>

/*
 * name:      ArrayList default constructor
 * purpose:   initialize an empty ArrayList
 * arguments: none
 * returns:   none
 * effects:   numItems and capacity to 0 
 */
CharArrayList::CharArrayList(){
    numItems = 0;
    capacity = 0;
    array = nullptr;
}

/*
 * name:      ArrayList second constructor 
 * purpose:   creates a one element array list with the character that it takes as a parameter
 * arguments: a character which will be the first element of the array
 * returns:   none
 * effects:   capacity  and numItems to 1 
 */
CharArrayList::CharArrayList(char a){
    numItems = 1;
    capacity = 1;
    char *new_arr = new char[capacity];
    new_arr[0] = a;
    array = new_arr;
    new_arr = nullptr;
}

/*
 * name:      ArrayList third constructor 
 * purpose:   creates an array list containing the characters in the provided array
 * arguments: array of characters and integer length of the array of characters
 * returns:   none
 * effects:   numItems and capacity to integer length of the array (size) 
 */
CharArrayList::CharArrayList(char arr[], int size){
    numItems = size;
    capacity = size;
    char *new_arr = new char[capacity];
    for (int i = 0; i < size ; i++){
        new_arr[i] = arr[i];
    }
    array = new_arr;
    new_arr = nullptr;
}


/*
 * name:      ArrayList fourth constructor 
 * purpose:   makes a deep copy of a given instance 
 * arguments: am instance of the array list to be copied
 * returns:   none
 * effects:   numItems and capacity updated to the instance of array list
 */
CharArrayList::CharArrayList(const CharArrayList &other){
    numItems = other.numItems;
    capacity = other.capacity;
    array = new char[capacity];
    for (int i = 0; i < numItems; i++){
        array[i] = other.array[i];
    }            
}

/*
 * name:      ArrayList destructor 
 * purpose:   deletes the data stored in heap to prevent memory leaks
 * arguments: none
 * returns:   none
 * effects:   recycles heap memory
 */
CharArrayList::~CharArrayList(){
    delete []array;
    array = nullptr;
}

/*
 * name:      Assignment Operator
 * purpose:   makes a deep copy of the instance on the right hand side into
 *            the instance on the left hand side
 * arguments: none
 * returns:   none
 * effects:   recycles the storage associated with the instance on the left
 *            numItems and capacity of the instance on the left is updated to
 *            the instance on the left 
 */
CharArrayList &CharArrayList::operator=(const CharArrayList &other){
    //checks if LHS and RHS of the operator are the same instances of
    //array list and if so doesn't update LHS
    if (this == &other){
        return *this;
    }

    delete [] array;
    array = nullptr;
    numItems = other.numItems;
    capacity = other.capacity;

    
    if (size() != 0){                           //checks if the instance on  
        array = new char[capacity];             //the left is an empty list
        for (int i = 0; i < numItems; i++){     //if not, elements in LHS are 
                array[i] = other.array[i];      //copied to RHS array list                       
        }

    }

    return *this;
}


/*
 * name:      isEmpty 
 * purpose:   checks if the instance  of the array list is empty or not
 * arguments: none
 * returns:   true if the instance of the array list is empty and false if not
 * effects:   none
 */
bool CharArrayList::isEmpty() const{
    bool is_empty = false;
    if (numItems == 0){
        is_empty = true;
    }
    //returns true if array has size 0 and false if not
    return is_empty;
}

/*
 * name:      clear 
 * purpose:   makes the instance into an array list
 * arguments: none
 * returns:   none
 * effects:   heap memory is recycled
 */
void CharArrayList::clear() {
    numItems = 0;
    capacity = 0;
    delete []array;
    array = nullptr;
}

/*
 * name:      size 
 * purpose:   provides an integer value that is the number of characters in
 *            the array list
 * arguments: none
 * returns:   number of items/character in the array list
 * effects:   none
 */
int CharArrayList::size() const{
    //returns the size of the array
    return numItems;
}

/*
 * name:      first 
 * purpose:   provides the first element in the array list
 * arguments: none
 * returns:   the first character in the array list
 * effects:   throws a runtime error if the array list is empty
 */
char CharArrayList::first() const{
    //throws error if array list is empty
    if(isEmpty()){
        throw std::runtime_error("cannot get first of empty ArrayList");
    }
    //returns the first element of the array list
    return array[0];
}

/*
 * name:      last 
 * purpose:   provides the last element in the array list
 * arguments: none
 * returns:   the last character in the array list
 * effects:   throws a runtime error if the array list is empty
 */
char CharArrayList::last() const{
    //throws error if array list is empty
    if(isEmpty()){
        throw std::runtime_error("cannot get last of empty ArrayList");
    }
    //returns the first element of the array list
    return array[numItems-1];
}


/*
 * name:      elementAt 
 * purpose:   provides the character in the given index of the array list
 * arguments: none
 * returns:   the character in the given index of the array list 
 * effects:   throws a range error if an index that is entered is out of 
 *            the array list 
 */
int CharArrayList::elementAt(int index) const{
     //throws error if index is out of range
    if (index < 0 or index >= numItems){
        throw std::range_error("index (" + std::to_string(index) +
                ") not in range [0.." + 
                std::to_string(this->size())+")");

    }
    //returns the element at the given index
    return array[index];
}


/*
 * name:      toString 
 * purpose:   returns a string which contains the characters of the array list
 * arguments: none
 * returns:   a string with the characters of array list in order
 * effects:   throws a message that includes the string 
 */
std::string CharArrayList::toString() const{
    std::string message = "";
    //case when the array list is not empty
    if (numItems > 0){
            //creates a string with the characters of the array list in order
            std::string char_list = "";
            for (int i = 0; i <numItems; i++){
                    char_list += elementAt(i);
            }
            //inserts the string in the message
            message = "[CharArrayList of size " + std::to_string(size()) 
                        + " <<" + char_list + ">>]";
    }
    //case when the array list is empty
    else if (numItems == 0){
         message = "[CharArrayList of size 0 <<>>]";
    }
    //returns the message
    return message;
}

/*
 * name:      toStringReverse 
 * purpose:   returns a string which contains the characters of the array list
 *            in the reverse order
 * arguments: none
 * returns:   a string with the characters of array list in the reverse order
 * effects:   throws a message that includes the string 
 */
std::string CharArrayList::toReverseString() const{
    std::string message = "";
    //case when the array list is not empty
    if (numItems > 0){
        //creates a string with the characters of the array list in reverse order
        std::string char_list = "";
        for (int i = 1; i <= numItems ; i++){
            char_list += elementAt(numItems - i);
        }
        //inserts the string in the message
        message = "[CharArrayList of size " + std::to_string(size()) 
                    + " <<" + char_list + ">>]";
    }
    //case when the array list is empty
    else if (numItems == 0){
        message = "[CharArrayList of size 0 <<>>]";
    }
    //returns the message
    return message;
}

/*
 * name:      expand 
 * purpose:   increase the capacity of the array list
 * arguments: none
 * returns:   none
 * effects:   increase the capacity 
 */
void CharArrayList::expand(){
    //allocate new larger array
    char *new_arr = new char[2*capacity+2];

    //copy over elements from the old array
    for (int i = 0; i < numItems; i++){
        new_arr[i] = array[i];
    }
    //recycle array
    delete[]array;
    //update member variables
    array = new_arr;
    capacity = 2*capacity+2;
    new_arr = nullptr;
}

/*
 * name:      pushAtBack 
 * purpose:   inserts the given element at the end of the exisiting elements in the array list
 * arguments: the character to be inserted at the end of the array list
 * returns:   none
 * effects:   numItems increased by 1, capacity is increased if necessary
 */
void CharArrayList::pushAtBack(char c){
    //increases the capacity if the array list is already fully populated
    if(numItems == capacity){
        expand();
    }
    //inserts the given character at the end of the array
    array[numItems] = c;
    //updates the numItems of the instance of array list
    numItems ++;
}


/*
 * name:      pushAtFront 
 * purpose:   inserts the given element in front of the exisiting elements in
 *            the array list
 * arguments: the character to be inserted in front of the array list
 * returns:   none
 * effects:   numItems increased by 1, capacity is increased if necessary
 */
void CharArrayList::pushAtFront(char c){
    //increases the capacity if the array list is already fully populated
    if(numItems == capacity){
        expand();
    }
    //allocate a larger array
    char *new_list = new char[capacity];
    //inserts the given character at the end of the array
    new_list[0] = c;
    //copy the elements of the old to the rest of the slots in the larger array 
    for (int i = 0; i < numItems; i++){
        new_list[i+1] = array[i];
    }
    //recycle array
    delete []array;
    //update member variables
    numItems ++;
    array = new_list;
    new_list = nullptr;  
}

/*
 * name:      insertAt 
 * purpose:   inserts the given element at the specified index and shifts the 
 *            existing elements as necessary
 * arguments: character to be inserted in the array list and the index to 
 *            insert the character
 * returns:   none
 * effects:   numItems increased by 1
 */
void CharArrayList::insertAt(char c, int index){
    if(numItems == capacity){       //increases the capacity if the array 
        expand();                   //list is already fully populated
    }
    if (index == 0){                //case if the index to insert the 
        pushAtFront(c);             //character is 0 (front of the list)
    }
    else if (index == numItems){    //case if the index to insert the 
        pushAtBack(c);              //character is numItems (end of the list)
    }
    //case if the index to insert the character is between 0 and numItems
    else if (index > 0 and index < numItems){
        //allocate a larger array
        char *new_list = new char[capacity];
        for (int i = 0; i < index; i ++){ //copy the elements before the 
                new_list[i] = array[i];   //specified index in old the 
        }                                 //array to the larger array
        //insert the character in the specified index in the larger array
        new_list[index] = c;
        for (int i = index; i < numItems; i ++){ //copy the elements after the
            new_list[i+1] = array[i];            //specified index in old the
        }                                        //array to the larger array
        delete []array;     //recycle array
        numItems ++;        //update member variables
        array = new_list;
        new_list = nullptr;  
    }else{ //throw an error if the index is out of range
        throw std::range_error("index (" + std::to_string(index) +
                    ") not in range [0.." + std::to_string(this->size())+"]");
    }
}


/*
 * name:      insertInOrder 
 * purpose:   inserts the given character into the array list in alphabetical order
 * arguments: character to be inserted into the array list
 * returns:   none
 * effects:   none
 */
void CharArrayList::insertInOrder(char c){
    //inserts the character to the front of the array list if its empty
    if (isEmpty()){
        insertAt(c, 0);
    }
    //inserts the character to the front of the array list if its nonempty
    else{
        int index = 0;    
        //finds the index to insert the character so that its in order
        for (int i = 0; i <numItems ; i++){
                if(c > array[i]){
                    index++;
                }
        }
        insertAt(c, index);
    }
}

/*
 * name:      popFromFront 
 * purpose:   removes the first element from the array list
 * arguments: none
 * returns:   none
 * effects:   numItems is decreased by 1
 */
void CharArrayList::popFromFront(){
    //throws a runtime error if the array list is empty
    if (isEmpty()){
            throw std::runtime_error("cannot pop from empty ArrayList");
    }
    else{
        //allocate a new array
        char *new_list = new char[capacity];
        //copy the elements of the old array starting from 
        //index 1 to the new array starting from index 0
        for (int i = 0; i < numItems-1; i++){
                new_list[i] = array[i+1];
        }
        //recycle array
        delete []array;
        //update member variables
        numItems --;
        array = new_list;
        new_list = nullptr; 
    }
}

/*
 * name:      popFromFront 
 * purpose:   removes the last element from the array list
 * arguments: none
 * returns:   none
 * effects:   numItems is decreased by 1
 */
void CharArrayList::popFromBack(){
    //throws a runtime error if the array list is empty
    if(isEmpty()){
        throw std::runtime_error("cannot pop from empty ArrayList");
    }
    else{
        //allocate a new array
        char *new_list = new char[capacity];
        //copy the elements of the old array list except
        //the last element to the new array list
        for (int i = 0; i < numItems-1; i++){
            new_list[i] = array[i];
        }
        //recycle array
        delete []array;
        //update member variables
        numItems --;
        array = new_list;
        new_list = nullptr;
    }
}

/*
 * name:      removeAt 
 * purpose:   removes the element at the specified index in the array list
 * arguments: index of the character to be removed
 * returns:   none
 * effects:   numItems is decreased by 1
 */
void CharArrayList::removeAt(int index){              
    if (index == 0){                //case if the index to remove the 
        popFromFront();             //characer is 0 (front of the list)
    }
    else if (index == numItems - 1){ //case if the index to remove the
        popFromBack();               //character is numItems (end of the list)
    }
    //case if the index to remove the character is between 0 and numItems
    else if(index > 0 and index < numItems-1){
        //allocate a new array
        char *new_list = new char[capacity];  
        for (int i = 0; i < index; i ++){ //copy the elements of old array list
            new_list[i] = array[i];       //before the index to the new list 
        }   
        for (int i = index + 1; i < numItems; i ++){ 
            new_list[i-1] = array[i];   //copy the elements of old array list 
        }                               //after the index to the new list
        //recycle the array
        delete [] array;
        //update the member variables
        numItems --;
        array = new_list;
        new_list = nullptr;
    }else{  //throw an error if the index is out of range
        throw std::range_error("index (" + std::to_string(index) 
                +") not in range [0.." + std::to_string(this->size())+")");
    }
}

/*
 * name:      replaceAt 
 * purpose:   replaces the element at the specified index with the new element
 * arguments: character to replace and the index to insert the given character
 * returns:   none
 * effects:   none
 */
void CharArrayList:: replaceAt(char c, int index){
    //remove the character at the specified index
    removeAt(index);
    //insert the given character at the specified index
    insertAt(c, index);
}

/*
 * name:      concatenate 
 * purpose:   adds a copy of the array list pointed to by the parameter value 
 *            to the end of the array list the function was called from
 * arguments: pointer to a second array list
 * returns:   none
 * effects:   none
 */
void CharArrayList::concatenate(CharArrayList *other){
    if (other->size() != 0){
            for (int i = 0; i <other->size(); i++){
                pushAtBack(other->elementAt(i));
            }
    }
}

/*
 * name:      shrink
 * purpose:   shrinks the memmory usage to bare minimum required
 * arguments: none
 * returns:   none
 * effects:   none
 */
void CharArrayList::shrink(){
    //new pointer to array of chars on heap memory created
    char *new_arr = new char[numItems];
    
    //the characters from the old array list is copied to the new one
    for (int i = 0; i < numItems; i++){
        new_arr [i] = array[i];
    }
    
    //old array is recycled
    delete [] array;
    
    //the capacity is updated to the size
    capacity = numItems;
    
    //the old array is updated to the new array
    array = new_arr;
    
    //created array is recycled
    new_arr = nullptr;
}

