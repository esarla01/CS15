/*
 *  CharLinkedList.cpp
 *  Erin Sarlak
 *  February 3, 2021
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  This file contains the imlementation of the CharLinkedList, which is the
 *  code for functions of the class.
 *
 */

#include "CharLinkedList.h"
#include <string>
#include <stdexcept>
#include <iostream>

/*
 * name:      Linkedlist default constructor
 * purpose:   initialize an empty linked list
 * arguments: none
 * returns:   none
 * effects:   list length to 0 
 */
 CharLinkedList::CharLinkedList(){
    front = nullptr;
    back = nullptr;
    list_length = 0;
 }


/*
 * name:      newNode
 * purpose:   creates a new node on the heap with data newData, next node as
 *            given newNode, and previous node as given prevNode
 * arguments: none
 * returns:   none
 * effects:   list length to 0 
 */
CharLinkedList::Node *CharLinkedList::new_Node (char newData, 
                                                Node *newNext, Node *newPrev){
    //allocate a new node on the heap                                                
    Node *new_node = new Node;
    //update its member variables(next, prev, and data) accordingly
    new_node->next = newNext;
    new_node->prev = newPrev;
    new_node->data = newData;
    //return the node
    return new_node;
}


 /*
 * name:      Linkedlist second constructor
 * purpose:   creates a one element linked list with the character that it
 *            takes as a parameter
 * arguments: none
 * returns:   none
 * effects:   list length to 0 
 */
 CharLinkedList::CharLinkedList(char c){
    //allocate a new node in the heap with the given character
    //next and prev of new node points at nullptr
    Node *newNode = new_Node(c, nullptr, nullptr);

    //front and back points at newNode
    front = newNode;
    back = newNode;

    //list length equals 1
    list_length = 1;
 }


/*
 * name:      LinkList third constructor 
 * purpose:   creates an linked list containing the characters in the provided array
 * arguments: array of characters and integer length of the array
 * returns:   none
 * effects:   list length to integer length of the array (size) 
 */
CharLinkedList::CharLinkedList(char arr[], int size){
   list_length = 0;
   //insert the elements of arr at the end of 
   //the instance of linked list in order
   for (int i = 0; i < size; i++){
         pushAtBack(arr[i]);
   }
}


/*
 * name:      ArrayList fourth constructor 
 * purpose:   makes a deep copy of a given instance 
 * arguments: an instance of the linked list to be copied
 * returns:   none
 * effects:   list length to updated to the instance of array list
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other){
    list_length = 0;
    //checks if the instance of linked list on LHS is empty
    if(other.isEmpty()){
         //assigns front and back pointers at nullptr
         front = nullptr;
         back = nullptr;
    }
    else {
         //copies the elements of the instance of linked list  
         //on LHS into the instance of linked list on RHS
         for (int i = 0; i < other.size(); i++){
               pushAtBack(other.elementAt(i));
         }   
    }         
}


  /*
 * name:      Linkedlist destructor
 * purpose:   recycles all heap-allocated data in the linked list
 * arguments: none
 * returns:   none
 * effects:   heap is cleared
 */
 CharLinkedList::~CharLinkedList(){
   //all heap allocated data are deleted  
   //with the helper recursive function
   recycleRecursive(front);
 }


 /*
 * name:      recycleRecursive
 * purpose:   recycles all heap-allocated data starting from currNode
 * arguments: none
 * returns:   none
 * effects:   none
 */
 void CharLinkedList::recycleRecursive(Node *currNode){
   //base case: function terminates when next of currNode is a nullptr
   if (currNode == nullptr){
      return;
   }
   //recursive case: deletes the node starting from the end of the list
   else {
      recycleRecursive(currNode->next);
      delete currNode;
   }
 }


/*
 * name:      Assignment Operator
 * purpose:   makes a deep copy of the instance on the right hand side into
 *            the instance on the left hand side
 * arguments: none
 * returns:   none
 * effects:   recycles the storage associated with the instance on the left
 *            list length of the instance on the left is updated to
 *            the instance on the right 
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other){
    //checks if the instances on the LHS and RHS of the operator are the
    //same linked lists and if so, then it returns LHS without updating it
    if (this == &other){
        return *this;
    }
    else {
         //makes the instance into an empty list
         clear();
         
         //copies the elements of the instance of linked list 
         //on LHS into the instance of linked list on RHS
         for (int i = 0; i < other.size(); i++){
                  pushAtBack(other.elementAt(i));
               }  

         return *this; 
       } 
   }  



 /*
 * name:      isEmpty
 * purpose:   returns a boolean value that is true if this specific instance 
 *            of linked list is empty and false if not
 * arguments: none
 * returns:   trueif linked list is empty and false otherwise 
 * effects:   none
 */
 bool CharLinkedList::isEmpty() const{
    bool isEmpty = false;
    if (list_length == 0){
       isEmpty = true;
    }
   return isEmpty;
}


/*
 * name:      clear 
 * purpose:   makes the instance into an linked list
 * arguments: none
 * returns:   none
 * effects:   heap memory is recycled
 */
void CharLinkedList::clear() {
   //all heap allocated data are deleted  
   //with the helper recursive function
   recycleRecursive(front);
   //updates member variables
   front = nullptr;
   back = nullptr;
   list_length = 0;
}


/*
 * name:      size
 * purpose:   provides size of the instance of a linked list 
 * arguments: none
 * returns:   return length of the linked list
 * effects:   none
 */
int CharLinkedList::size() const{
   //returns list length
   return list_length;
}


/*
 * name:      first
 * purpose:   returns the first element (char) in the linked list
 * arguments: none
 * returns:   first character in the list
 * effects:   throws a runtime_error exception if the list is empty
 */
char CharLinkedList::first() const{
   //checks if the linked list is empty
   if (isEmpty()){
      //throws a runtime_error if the list is empty
      throw std::runtime_error("cannot get first of empty LinkedList");  
   }
   else{
      //return the first character if the list is popullated
      return front->data;
   }
}


/*
 * name:      false
 * purpose:   returns the last element (char) in the linked list
 * arguments: none
 * returns:   last character in the list
 * effects:   throws a runtime_error exception if the list is empty
 */
char CharLinkedList::last() const{
   //checks if the linked list is empty
   if (isEmpty()){
      //throws a runtime_error if the list is empty
      throw std::runtime_error("cannot get last of empty LinkedList");  
   }
   else{
      //return the last character if the list is popullated
      return back->data;
   }
}


 /*
 * name:      pushAtFront
 * purpose:   inserts the given new element in front of the existing elements
 *            of the list
 * arguments: none
 * returns:   none
 * effects:   numItems increases by 1
 */
 void CharLinkedList::pushAtFront(char c){
   //if linked list is empty
   if (isEmpty()){
         //create a new node whose next and prev points at nullptr
         Node *newNode = new_Node(c, nullptr, nullptr);
         //update front and back to new node
         front = newNode;
         back = newNode;
         //list length is increased by 1
         list_length ++;
   }
   //if linked list is nonempty
   else {
      //create a new node whose next points at the 
      //first element and prev points at nullptr
      Node *newNode = new_Node(c, front , nullptr);
      //update the prev of the node that used to be the first
      newNode->next->prev = newNode;
      //new node becomes the first node as front points at it
      front = newNode;
      //list length is increased by 1
      list_length ++;
   }
}


/*
 * name:      pushAtBack
 * purpose:   inserts the given new element at the end of the existing elements
 *            of the list
 * arguments: none
 * returns:   none
 * effects:   numItems increases by 1
 */
 void CharLinkedList::pushAtBack(char c){
   //if linked list is empty
   if (isEmpty()){
         //create a new node whose next and prev points at nullptr
         Node *newNode = new_Node(c, nullptr, nullptr);
         //update front and back to new node
         front = newNode;
         back = newNode;
         //list length is increased by 1
         list_length ++;
   }
   //if linked list is nonempty
   else {
      //create a new node whose prev points at the 
      //last element and next points at nullptr
      Node *newNode = new_Node(c, nullptr , back);
      //update front and back to new node
      newNode->prev->next = newNode;
      //new node becomes the last node as back points at it
      back = newNode;
      //list length is increased by 1
      list_length ++;
   }
}


/*
 * name:      elementAt
 * purpose:   provides the element (char) in the list at that index
 * arguments: none
 * returns:   element (char) in the list at that index
 * effects:   throws and error if index is out of bounds 
 */
char CharLinkedList::elementAt(int index) const{
   if (index < 0 or index > list_length - 1){
      //throws an error message when the index is out of range
      throw std::range_error("index (" + std::to_string(index) +
                ") not in range [0.." + 
                std::to_string(this->list_length) + ")");
   }
   else {
      //calls recursiveElementAt function to return 
      //the character at the specified index
      return recursiveElementAt(index,front);
   }
}


/*
 * name:      recursiveElementAt
 * purpose:   return the element in the list at the specified index 
 * arguments: index of an element and node that 
 *            specifies the start of recursion 
 * returns:   element (char) in the list at that index
 * effects:   none 
 */
char CharLinkedList::recursiveElementAt(int index, Node *currNode) const{
   //base case:  when currNode points at the node 
   //at the specified index and returns its data  
   if (index == 0){
      return currNode->data;
   }
   //recursive case: currNode increments through 
   //the linked list with a count down
   else{
      index --;
      currNode = currNode->next;
      return recursiveElementAt(index,currNode);
   }
}


/*
 * name:      insertAt 
 * purpose:   inserts the given element at the specified index
 * arguments: character to be inserted in the linked list and the index to 
 *            insert the character
 * returns:   none
 * effects:   throws a runtime error if index is out of bounds and list_length
 *            is increased by 1 
 */
void CharLinkedList::insertAt(char c, int index){
   //inserts in front of the list
   if (index == 0){
         pushAtFront(c);
   }
   //inserts at the back of the list
   else if (index == size()){
         pushAtBack(c);
   }
   //inserts in the middle of the list
   else if (index > 0 and index < size()){
         Node *currNode = front;
         //finds the node before that is one before the index
         for (int i = 0; i < index - 1; i ++){
               currNode = currNode->next;
         }
         //creates a node and updates next and prev
         Node *newNode = new_Node(c, currNode->next, currNode);
         currNode->next->prev = newNode;
         currNode->next = newNode;
         //list length is increased by 1
         list_length ++;
   }
   else {
      //throws a range error if the index is out of bounds
      throw std::range_error("index (" + std::to_string(index) +
                ") not in range [0.." + 
                std::to_string(this->size())+"]");
   }
}


/*
 * name:      popFromFront 
 * purpose:   removes the first element from the array list
 * arguments: none
 * returns:   none
 * effects:   numItems is decreased by 1
 */
void CharLinkedList::popFromFront(){
   if (isEmpty()){
      throw std::runtime_error ("cannot pop from empty LinkedList");
   }
   else if(size() == 1){
      delete back;
      front  = nullptr;
      back = nullptr;
      list_length --;
   }
   else {
      Node *currNode = front;
      front = currNode->next;
      currNode->next->prev = nullptr;
      delete currNode;
      list_length --;
   }
}


/*
 * name:      popFromFront 
 * purpose:   removes the last element from the array list
 * arguments: none
 * returns:   none
 * effects:   numItems is decreased by 1
 */
void CharLinkedList::popFromBack(){
   if (isEmpty()){
      throw std::runtime_error ("cannot pop from empty LinkedList");
   }
   else if(size() == 1){
      delete back;
      front  = nullptr;
      back = nullptr;
      list_length --;
   }
   else {
      Node *currNode = back;
      back = currNode->prev;
      currNode->prev->next = nullptr;
      delete currNode;
      list_length --;
   }
}


/*
 * name:      removeAt 
 * purpose:   removes the element at the specified index in the linked list
 * arguments: index of the character to be removed
 * returns:   none
 * effects:   throws a runtime error if index is out of bounds and list_length
 *            is increased by 1 
 */
void CharLinkedList::removeAt(int index){
   if (index == 0){
         popFromFront();
   }
   else if (index == size()-1){
         popFromBack();
   }
   else if (index > 0 and index < size()){
         Node *currNode = front;
         for (int i = 0; i < index; i ++){
               currNode = currNode->next;
         }
         currNode->prev->next = currNode->next;
         currNode->next->prev = currNode->prev;
         delete currNode;
         list_length --;
   }
   else {
      throw std::range_error("index (" + std::to_string(index) +
                ") not in range [0.." + 
                std::to_string(size())+")");
   }
}


/*
 * name:      toStringReverse 
 * purpose:   returns a string which contains the characters of the linked list
 *            in the reverse order
 * arguments: none
 * returns:   a string with the characters of linked list in the reverse order
 * effects:   none
 */
std::string CharLinkedList::toString() const{
   std::string message = "";
   //case when the array list is not empty
    if (size() > 0){
   //creates a string with the characters of the array list in order
            std::string char_list = "";
            for (int i = 0; i <size(); i++){
                    char_list += elementAt(i);
            }
            //inserts the string in the message
            message = "[CharLinkedList of size " + std::to_string(size()) 
                        + " <<" + char_list + ">>]";
    }
    //case when the array list is empty
    else if (size() == 0){
         message = "[CharLinkedList of size 0 <<>>]";
    }
    //returns the message
    return message;
}

/*
 * name:      toStringReverse 
 * purpose:   returns a string which contains the characters of the linked list
 *            in the reverse order
 * arguments: none
 * returns:   a string with the characters of linked list in the reverse order
 * effects:   throws a message that includes the string 
 */
std::string CharLinkedList::toReverseString() const{
    std::string message = "";
    //case when the array list is not empty
    if (size() > 0){
        //creates a string with the characters of the array list in reverse order
        std::string char_list = "";
        for (int i = 1; i <= size() ; i++){
            char_list += elementAt(size() - i);
        }
        //inserts the string in the message
        message = "[CharLinkedList of size " + std::to_string(size()) 
                    + " <<" + char_list + ">>]";
    }
    //case when the array list is empty
    else if (size() == 0){
        message = "[CharLinkedList of size 0 <<>>]";
    }
    //returns the message
    return message;
}


/*
 * name:      insertInOrder 
 * purpose:   inserts the given character into the linked list in alphabetical
 *            order
 * arguments: character to be inserted into the linked list
 * returns:   none
 * effects:   none
 */
void CharLinkedList::insertInOrder(char c){
   if (size() == 0){
      pushAtFront(c);
   }
   else {
      int index = 0;
      //finds the index at which char c is to be inserted
      for (int i = 0; i < size(); i++){
         //compares the characters in the list and char c in order
             if(c > elementAt(i)){
               //increments index untill char c is smaller than the 
               //following char in the list or at the end of the list
                  index ++;
            }
      }
      insertAt(c, index);
   }
}


/*
 * name:      recursiveElementAt
 * purpose:   replace the element in the linked list at the specified index
 *            with char c 
 * arguments: index of an element, character to replace with, node that 
 *            specifies the start of recursion 
 * returns:   none
 * effects:   none 
 */
void CharLinkedList::recursivereplaceAt(char c, int index, Node *currNode) {
   //base case:  when currNode points at the node 
   //at the specified index, replaces its data
   if (index == 0){
      currNode->data = c;
      return;
   }
   //recursive case: currNode increments through 
   //the linked list with a count down
   else{
      index --;
      currNode = currNode->next;
      recursivereplaceAt(c, index, currNode);
   }
}


/*
 * name:      replaceAt 
 * purpose:   replaces the element at the specified index with the new element
 * arguments: character to replace and the index to insert the given character
 * returns:   none
 * effects:   none
 */
void CharLinkedList:: replaceAt(char c, int index){
   if(index >= 0 and index < size()){
         //calls recursivereplaceAt function to replace the
         //element  at the specified index with char c
         recursivereplaceAt(c, index, front);
   }
   else{
      throw std::range_error("index (" + std::to_string(index) +
                ") not in range [0.." + 
                std::to_string(this->list_length) + ")");
   }

}


/*
 * name:      concatenate 
 * purpose:   adds a copy of the linked list pointed to by the parameter value 
 *            to the end of the linked list the function was called from
 * arguments: pointer to a second linked list
 * returns:   none
 * effects:   none
 */
void CharLinkedList::concatenate(CharLinkedList *other){
   int elements = other->size();
         for (int i = 0; i < elements; i++){
                pushAtBack(other->elementAt(i));
            }
}
