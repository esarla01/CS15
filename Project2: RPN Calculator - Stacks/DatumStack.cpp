/* PROJ2
 * Tansu Erin Sarlak
 * 04/01/2022
 * Implementation for DatumStack Class
 */

#include <iostream>
#include <string>
#include <vector>
#include "DatumStack.h"
#include "Datum.h"

/*
 * name:      DatumStack
 * purpose:   initializes an empty stack
 * arguments: none
 * returns:   none
 * effects:   none
 */
DatumStack::DatumStack()
{

}

/*
 * name:      DatumStack
 * purpose:   creates a stack that has the elements of the array
 * arguments: populated datum array and its size
 * returns:   none
 * effects:   none
 */
DatumStack::DatumStack( Datum arr[], int size)
{
    for (int i = 0; i < size; i++){
        stack.push_back(arr[i]);
    }
}


/*
 * name:      isEmpty
 * purpose:   return true if stack is populated and false if is empty 
 * arguments: none
 * returns:   boolean value that is true if the stack if empty and false 
 *            otherwise
 * effects:   none
 */
bool DatumStack::isEmpty(){
    bool isEmpty = false;
    if (stack.size() == 0){
        isEmpty = true;
    }
    return isEmpty;
}


/*
 * name:      clear
 * purpose:   makes the current stack into an empty stack 
 * arguments: none
 * returns:   none
 * effects:   none
 */
void DatumStack::clear(){
    stack.clear();
}


/*
 * name:      size
 * purpose:   return the number of Datum elements on the stack
 * arguments: none
 * returns:   integer value that is the size of the stack
 * effects:   none
 */
int DatumStack::size(){
    return stack.size();
}


/*
 * name:      top   
 * purpose:   returns the top Datum element on the stack
 * arguments: none
 * returns:   the last elemet of the stack
 * effects:   none
 */
Datum DatumStack::top()
{
    if (isEmpty()){
        //throws an error if stack is empty
      throw std::runtime_error("empty_stack");  
   }
   else{
       return stack.back();
   }
}


/*
 * name:      top   
 * purpose:   removes the top element on the stack
 * arguments: none
 * returns:   none
 * effects:   none
 */
void DatumStack::pop()
{
    if (isEmpty()){
        //throws an error if stack is empty
      throw std::runtime_error("empty_stack");  
   }
   else{
        stack.pop_back();
   }
}


/*
 * name:      push   
 * purpose:   takes a Datum element and puts it on the top of the stack
 * arguments: Datum element to be added on the stack
 * returns:   none
 * effects:   none
 */
void DatumStack::push(Datum element)
{
    stack.push_back(element);

}


/*
 * name:   print  (used only in testing) 
 * purpose:   print the contents of the stack in order
 * arguments: none
 * returns:   none
 * effects:   none
 */
// void DatumStack::print()
// {
//     for (unsigned int i = 0; i < stack.size(); i++){

        
//         if (stack[i].isInt()){
           
//             std::cout <<stack[i].getInt();
//         }
//         else if (stack[i].isBool()){

//             std::cout <<stack[i].getBool();
//         }
//         else if (stack[i].isRString()){

//             std::cout <<stack[i].getRString();
//         }
//     }
// }