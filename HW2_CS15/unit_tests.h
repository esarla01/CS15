/*
 *  unit_tests.h
 *  Erin Sarlak
 *  February 4, 2022
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  This file contains the codes that test the functions of the 
*   CharLinkedList class.
 *
 */

#include "CharLinkedList.h"
#include <cassert>
#include <string>
#include <stdexcept>
#include <iostream>

/*
 * first constructor test 
 * Make sure that instance of a linked list that is empty is created.
 */
void constructor1_test(){
    CharLinkedList list;
}


/*
 * second constructor test 
 * Make sure that instance of a linked list that has a first element 
 * which is the character provided as the parameter.
 */
void constructor2_test(){
    CharLinkedList list('a');
    assert(list.size() == 1);
    assert(list.elementAt(0) == 'a');
}

/*
 * third constructor test 
 * Make sure the linked list has the elements and capacity of the argument 
 * linked list.
 */
 void constructor3_test() {
    char test_arr[3] = { 'a', 'b', 'c'};
    CharLinkedList list(test_arr, 3);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'c');
    assert(list.size() == 3);
 }


/*
 * (copy) fourth constructor test empty
 * Make sure the array list properly deep copies an empty array list.
 */
void constructor4_empty(){
    CharLinkedList list_1st;
    CharLinkedList list_2nd(list_1st);
    assert(list_2nd.isEmpty() == true);
    assert(list_2nd.size() == 0);
}


/*
 * (copy) fourth constructor nonempty 
 * Make sure the array list porperly deep copies a nonempty array.
 */
void Constructor4_nonempty(){
    char test_arr[3] = { 'a', 'b', 'c'};
    CharLinkedList list_1st(test_arr, 3);
    CharLinkedList list_2nd(list_1st);
    assert(list_2nd.elementAt(0) == 'a');
    assert(list_2nd.elementAt(1) == 'b');
    assert(list_2nd.elementAt(2) == 'c');
    assert(list_2nd.size() == 3);
}


/*
 * operator test nonempty to empty
 * Make sure that a deep copy of the instance om the right hand side is made
 * into the instance on the left hand side and the storage associated with 
 * the instance on the left of the aassignment is recycled. This test is 
 * specifically for copying an nonempty list to a empty list.
 */
void operator_test_nonempty_to_empty(){
    CharLinkedList list_1st('a');
    CharLinkedList list_2nd;
    list_2nd = list_1st;
    assert(list_2nd.elementAt(0) == 'a');
    assert(list_2nd.size() == 1);
}


/*
 * operator test empty to nonempty
 * Make sure that a deep copy of the instance om the right hand side is made
 * into the instance on the left hand side and the storage associated with 
 * the instance on the left of the aassignment is recycled. This test is 
 * specifically for copying an empty list to a nonempty list.
 */
void operator_test_empty_to_nonempty(){
    CharLinkedList list_1st;
    CharLinkedList list_2nd('b');
    list_2nd = list_1st;
    assert(list_2nd.isEmpty() == true);
    assert(list_2nd.size() == 0);
}


/*
 * operator test nonempty2
 * Make sure that a deep copy of the instance on the right hand side is made
 * into the instance on the left hand side and the storage associated with 
 * the instance on the left of the assignment is recycled. This test is 
 * specifically for copying a nonempty list to another nonempty list.
 */
void operator_test_nonempty_to_nonempty(){
    char arr1[3] = { 'a', 'b', 'c' };
    CharLinkedList list_1st(arr1, 3);
    char arr2[2] = { 'x', 'y' };
    CharLinkedList list_2nd(arr2, 3);
    list_2nd = list_1st;
    assert(list_2nd.elementAt(0) == 'a');
    assert(list_2nd.elementAt(1) == 'b');
    assert(list_2nd.elementAt(2) == 'c');
    assert(list_2nd.size() == 3);
}   


/*
 * pushAtFront
*  Make sure that the function inserts given characters in front of an empty 
 * list list and updates the size accordingly.
 */
void pushAtFront_test(){
    CharLinkedList list;
    list.pushAtFront('a');
    list.pushAtFront('b');
    list.pushAtFront('c');
    assert(list.elementAt(0) == 'c');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'a');
    assert(list.size() == 3);
  
}


/*
 * pushAtBack
*  Make sure that the function inserts given characters at the end of an empty
 * linked list and updates the size accordingly.
 */
void pushAtBack_test(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'c');
    assert(list.size() == 3);
  
}


/*
 * isEmpty
 * Make sure that the function returns truw when the list is empty and false otherwise
 */
void isEmpty_test(){
    CharLinkedList list_1;
    assert(list_1.isEmpty() == true);

    CharLinkedList list_2('a');
    assert(list_2.isEmpty() == false);

}


/*
 * clear test empty
 * Make sure that the an empty linked list stays empty after the function is called
 * when it is not.
 */
void clear_test_empty(){
    CharLinkedList list;
    list.clear();
    assert(list.isEmpty() == true);
    assert(list.size() == 0);
}


/*
 * clear test nonempty
 * Make sure that the linked list is emptied after the function is called on an instance
 * of linked list
 * when it is not.
 */
void clear_test_nonempty(){
    char test_arr[3] = { 'a', 'b', 'c'};
    CharLinkedList list(test_arr, 3);
    list.clear();
    assert(list.isEmpty() == true);
    assert(list.size() == 0);
}


/*
 * first test nonempty
 * Tests if first function provides the first element of the linked list.
 */
void first_test_nonempty(){
    CharLinkedList list('a');
    assert(list.first() == 'a');

}


/*
 * first test 2
 * Tests if the function throws runtime error when it the linked list is empty
 */
void first_test_empty(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList list;

    try{
        list.first();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");

}


/*
 * last test nonempty
 * Tests if last function provides the last element of the linked list.
 */
void last_test_nonempty(){
    CharLinkedList list('a');
    assert(list.last() == 'a');

}


/*
 * last test empty
 * Tests if the function throws runtime error when it the linked list is empty
 */
void last_test_empty(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList list;

    try{
        list.last();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty LinkedList");

}



/*
 * popFromFront test nonempty
 * Make sure that the function removes the first character from the linked list 
 * when it is nonempty
 */
void popFromFront_test_nonempty(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.popFromFront();
    assert(list.elementAt(0) == 'b');
    assert(list.size() == 1);
}


/*
 * popFromFront test empty
 * Make sure that the function throws an error message when the linked list
 * is empty because no element can to be removed exists in the list
 */
void popFromFront_test_empty(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList list;
    try{
        list.popFromFront();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");

}



/*
 * popFromBack test empty
 * Make sure that the function throws an error message when the linked list
 * is empty because no element can to be removed exists in the list
 */
void popFromBack_test_nonempty(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.popFromBack();
    assert(list.elementAt(0) == 'a');
    assert(list.size() == 1);
}



/*
 * popFromBack test nonempty
 * Make sure that the function removes the last character from the linked list 
 * when it is nonempty
 */
void popFromBack_test_empty(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList list;

    try{
        list.popFromBack();
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");
}


/*
 * insertAt test front
 * Make sure that the function inserts in front of the linked list and
 * updates the size accordingly
 */
void insertAt_test_front(){
    CharLinkedList list;
    list.pushAtBack('b');
    list.insertAt('a', 0);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.size() == 2);
}


/*
 * insertAt test middle
 * Make sure that the function inserts in the middle of the linked list and
 * updates the size accordingly
 */
void insertAt_test_middle(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('c');
    list.insertAt('b', 1);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'c');
    assert(list.size() == 3);
}


/*
 * insertAt test back
 * Make sure that the function inserts at the back of the linked list and
 * updates the size accordingly
 */
void insertAt_test_back(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.insertAt('c', 1);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'c');
    assert(list.size() == 2);
}


/*
 * insertAt test back
 * Make sure that the function throws an error when the index entered is 
 * out of bounds
 */
void insertAt_error(){
    bool runtime_error_thrown = false;
    std::string error_message = "";
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');

    try{
        list.insertAt('c', 3);
    }
    catch(const std::runtime_error &e){
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(runtime_error_thrown);
    assert(error_message == "index (3) not in range [0..2]");
}


/*
 * removeAt test front 
 * Make sure that the function properly removes the first character from the 
 * linked list 
 */
void removeAt_test_front(){
    CharLinkedList list;;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.removeAt(0);
    assert(list.elementAt(0) == 'b');
    assert(list.size() == 1);
}


/*
 * removeAt test middle
 * Make sure that the function properly removes a character in the middle from the 
 * linked list 
 */
void removeAt_test_middle(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.removeAt(1);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'c');
    assert(list.size() == 2);
}


/*
 * removeAt test back 
 * Make sure that the function properly removes the last character from the 
 * linked list 
 */
void removeAt_test_back(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.removeAt(1);
    assert(list.elementAt(0) == 'a');
    assert(list.size() == 1);
}


/*
 * toString test empty
 * Make sure that the function returns the intended message when the linked 
 * list is empty.
 */
void toString_test_empty(){
    CharLinkedList list;
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");
}

/*
 * toString test nonempty
 * Make sure that the function returns the intended message when the linked 
 * list is nonempty (ordered string).
 */
void toString_test_nonempty(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    assert(list.toString() == "[CharLinkedList of size 3 <<abc>>]");

}


/*
 * toReverseString test empty
 * Make sure that the function returns the intended message when the linked 
 * list is empty.
 */
void toReverseString_test_empty(){
    CharLinkedList list;
    assert(list.toReverseString() == "[CharLinkedList of size 0 <<>>]");
}


/*
 * toReverseString test empty
 * Make sure that the function returns the intended message when the linked 
 * list is nonempty (reverse string).
 */
void toReverseString_test_nonempty(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    assert(list.toReverseString() == "[CharLinkedList of size 3 <<cba>>]");

}


/*
 * insertInOrder test empty first
 * Make sure that the specified characters are inserted into the linked list in
 * alpahbetical order when the function is called and array list is empty.
 */
void insertInOrder_test_empty_first(){
    CharLinkedList list;
    list.insertInOrder('c');
    assert(list.elementAt(0) == 'c');
    assert(list.size() == 1);
}

/*
 * insertInOrder test nonempty
 * Make sure that the specified characters are inserted into the linked list in
 * alpahbetical order when the function is called and list list is nonempty.
 */
void insertInOrder_test_nonempty_middle(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('c');
    list.insertInOrder('b');
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'c');
    assert(list.size() == 3);
}


/*
 * insertInOrder test empty last
 * Make sure that when the character is supposed to come after other character
 * the list, it is inserted to the end of the list.
 */
void insertInOrder_test_nonempty_last(){
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.insertInOrder('c');
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'c');
    assert(list.size() == 3);
}


/*
 * replaceAt_test() 
 * Make sure that the function properly replaces a character in the specified
 * index with the given index (replaces from front, middle, and back)
 */
void replaceAt_test_front(){ 
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('d');
    list.replaceAt('c',0);
    list.replaceAt('b',1);
    list.replaceAt('a',2);
    assert(list.elementAt(0) == 'c');            
    assert(list.elementAt(1) == 'b');
    assert(list.elementAt(2) == 'a');
}


/*
 * concanate test nonempty
 * Make sure that the list copies the characters of the second list to the 
 * first one when both lists are already popullated.
 */
void concanate_test_nonempty(){
    CharLinkedList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    CharLinkedList list_2nd;
    list_2nd.pushAtBack('d');
    list_2nd.pushAtBack('e');
    CharLinkedList *list_pointer;
    list_pointer = &list_2nd;
    list_1st.concatenate(list_pointer);
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
    assert(list_1st.elementAt(2) == 'd');
    assert(list_1st.elementAt(3) == 'e');
}

/*
 * concanate test empty
 * Make sure that the list copies the characters of the second list to the 
 * first one when the first list is empty but the second one is popullated
 */
void concanate_test_empty(){
    CharLinkedList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    CharLinkedList list_2nd;
    CharLinkedList *list_pointer;
    list_pointer = &list_2nd;
    list_1st.concatenate(list_pointer);
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
}


/*
 * concanate test self
 * Make sure that the list copies the characters of the second list to the 
 * first one when the first list is nonempty and the second one is first list
 */
void concanate_test_self(){
    CharLinkedList list_1st;
    list_1st.pushAtBack('a');
    list_1st.pushAtBack('b');
    CharLinkedList *list_pointer;
    list_pointer = &list_1st;
    list_1st.concatenate(list_pointer);
    assert(list_1st.elementAt(0) == 'a');
    assert(list_1st.elementAt(1) == 'b');
}

